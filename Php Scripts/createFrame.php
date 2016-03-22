<?php

    // o--------------------------------------------------------
    // | Input & Settings
    // o--------------------------------------------------------

    // These variables are sent from Unity, we access them via
    // $_POST and make sure to santitize the input to mysql.
    
    $animID     		= $_POST['animID'];
	$frameIndex     	= $_POST['frameIndex'];
	$duration			= $_POST['duration'];
	$frameDataLength	= $_POST['frameDataLength'];
	$fileName			= uniqid();
	$folder				= "C:" . DIRECTORY_SEPARATOR . DIRECTORY_SEPARATOR . "PlayTIME_Data" . DIRECTORY_SEPARATOR . DIRECTORY_SEPARATOR . "images" . DIRECTORY_SEPARATOR;
	//$myFile				= fopen($_FILES['frameData']['tmp_name'],'r');
	//$frameData			= fread($myFile, $frameDataLength);
	$path = $folder . DIRECTORY_SEPARATOR . $fileName;
	
	//echo($_FILES['frameData']['error']);

    // These settings define where the server is located, and
    // which credentials we use to connect to that server.  
    
    $server   = "localhost";
    $username = "admin";
    $password = "admin";
    
    // This is the database and table we are going to access in
    // the mysql server. In this example, we assume that we have
    // the table 'highscores' in the database 'gamedb'.
    
    $database = "playtimedb";
                     
    $insert   = "INSERT INTO `animframes` (`id`, `animid`, `frameindex`, `duration`, `data`) 
	VALUES (NULL, $animID, $frameIndex, $duration, '" . $path . "');";
	
	$select = "SELECT `id` FROM `animframes` ORDER BY `id` DESC LIMIT 1;";
	
	if(!file_exists($folder))
	{
		if(!mkdir($folder, null, true))
		{
			echo('Failed to create folder');
		}
		else
		{
			echo('created folder');
		}
	}
	
	if(!move_uploaded_file($_FILES['frameData']['tmp_name'], $path))
	{
		echo('move uploaded file failed');
	}

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error()); 
    $result = mysql_query($insert, $connection) or die($insert."<br/><br/>".mysql_error());
    $result = mysql_query($select, $connection) or die($select."<br/><br/>".mysql_error());

    // Finally, go through top 10 players and return the result
    // back to Unity. The output format for each line will be: 
    // {game}:{player}:{score}
    
    $row = mysql_fetch_array($result);
    echo $row['id'];
  
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>