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
	
	$select = "SELECT `data` FROM `animframes` WHERE `id` = $frameID;";

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error());
    $result = mysql_query($select, $connection) or die($select."<br/><br/>".mysql_error());
	
	$row = mysql_fetch_array($result);
	$fileName = $row['data'];
	
	if (file_exists($fileName)) 
	{
		header('Content-Description: File Transfer');
		header('Content-Type: application/octet-stream');
		header('Content-Disposition: attachment; filename="'.basename($fileName).'"');
		header('Expires: 0');
		header('Cache-Control: must-revalidate');
		header('Pragma: public');
		header('Content-Length: ' . filesize($fileName));
		readfile($fileName);
	}
	else
	{
		echo('file read failed');
	}
	
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>