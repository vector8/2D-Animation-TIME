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
	
	$selectFrames = "SELECT `id`, `frameindex`, `duration` FROM `animframes` WHERE `animid` = $animID;";

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error());
    $result = mysql_query($selectFrames, $connection) or die($selectFrames."<br/><br/>".mysql_error());
	
	while ($row = mysql_fetch_array($result))
        echo $row['id'] . "," 
		. $row['frameindex'] . "," 
		. $row['duration'] . ",<br>";
	
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>