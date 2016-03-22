<?php

    // o--------------------------------------------------------
    // | Input & Settings
    // o--------------------------------------------------------

    // These variables are sent from Unity, we access them via
    // $_POST and make sure to santitize the input to mysql.
    
    $id     			= $_POST['id'];
	$frameIndex     	= $_POST['frameIndex'];
	$duration			= $_POST['duration'];
	$frameDataLength	= $_POST['frameDataLength'];
	//$myFile				= fopen($_FILES['frameData']['tmp_name'],'r');
	//$frameData			= fread($myFile, $frameDataLength);

    // These settings define where the server is located, and
    // which credentials we use to connect to that server.  
    
    $server   = "localhost";
    $username = "admin";
    $password = "admin";
    
    // This is the database and table we are going to access in
    // the mysql server. In this example, we assume that we have
    // the table 'highscores' in the database 'gamedb'.
    
    $database = "playtimedb";
                     
	$select = "SELECT `data` FROM `animframes` WHERE `id` = $id;";
					 
    $update   = "UPDATE `animframes` SET `frameindex` = $frameIndex, `duration` = $duration WHERE `id` = $id;";

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error()); 
    $result = mysql_query($select, $connection) or die($select."<br/><br/>".mysql_error());
	
	$row = mysql_fetch_array($result);
    $fileName = $row['data'];
	
    $result = mysql_query($update, $connection) or die($update."<br/><br/>".mysql_error());
	
	if(!move_uploaded_file($_FILES['frameData']['tmp_name'], $fileName))
	{
		echo('move uploaded file failed');
	}
  
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>