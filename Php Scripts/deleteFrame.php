<?php

    // o--------------------------------------------------------
    // | Input & Settings
    // o--------------------------------------------------------

    // These variables are sent from Unity, we access them via
    // $_POST and make sure to santitize the input to mysql.
    
    $frameID     = $_POST['frameID'];

    // These settings define where the server is located, and
    // which credentials we use to connect to that server.  
    
    $server   = "localhost";
    $username = "admin";
    $password = "admin";
    
    // This is the database and table we are going to access in
    // the mysql server.
    
    $database = "playtimedb";
	
	$selectData = "SELECT `data` FROM animframes WHERE id = $frameID;";
	$selectFrameIndex = "SELECT frameindex, animid FROM animframes WHERE id = $frameID LIMIT 1 INTO @index, @animID;";
	$updateFrameIndices = "UPDATE animframes SET frameindex = frameindex - 1 WHERE frameindex > @index AND animid = @animID;";
	$deleteAnimFrames = "DELETE FROM `animframes` WHERE `id` = $frameID;";

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error());
	$result = mysql_query($selectData, $connection) or die($selectData."<br/><br/>".mysql_error());
	
	$row = mysql_fetch_array($result);
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
	
    $result = mysql_query($selectFrameIndex, $connection) or die($selectFrameIndex."<br/><br/>".mysql_error());
    $result = mysql_query($updateFrameIndices, $connection) or die($updateFrameIndices."<br/><br/>".mysql_error());
    $result = mysql_query($deleteAnimFrames, $connection) or die($deleteAnimFrames."<br/><br/>".mysql_error());
	
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>