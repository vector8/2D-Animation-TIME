<?php

    // o--------------------------------------------------------
    // | Input & Settings
    // o--------------------------------------------------------

    // These variables are sent from Unity, we access them via
    // $_POST and make sure to santitize the input to mysql.
    
    $animID     = $_POST['animID'];

    // These settings define where the server is located, and
    // which credentials we use to connect to that server.  
    
    $server   = "localhost";
    $username = "admin";
    $password = "admin";
    
    // This is the database and table we are going to access in
    // the mysql server.
    
    $database = "playtimedb";
	
	$select = "SELECT `data` FROM `animframes` WHERE `animid` = $animID;";
	$deleteAnimFrames = "DELETE FROM `animframes` WHERE `animid` = $animID;";
	$deleteFigAnims = "DELETE FROM `figanims` WHERE `animid` = $animID;";
	$deleteAnims = "DELETE FROM `animations` WHERE `id` = $animID;";

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error());
	$result = mysql_query($select, $connection) or die($select."<br/><br/>".mysql_error());
	
	while ($row = mysql_fetch_array($result))
	{
		$fileName = $row['data'];
		
		$success = FALSE;
		
		if(file_exists($fileName))
		{
			$success = unlink($fileName);
		}
		
		if(!$success)
		{
			echo('delete failed');
		}
	}
	
    $result = mysql_query($deleteAnimFrames, $connection) or die($deleteAnimFrames."<br/><br/>".mysql_error());
    $result = mysql_query($deleteFigAnims, $connection) or die($deleteFigAnims."<br/><br/>".mysql_error());
    $result = mysql_query($deleteAnims, $connection) or die($deleteAnims."<br/><br/>".mysql_error());
	
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>