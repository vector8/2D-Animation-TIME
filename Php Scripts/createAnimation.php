<?php

    // o--------------------------------------------------------
    // | Input & Settings
    // o--------------------------------------------------------

    // These variables are sent from Unity, we access them via
    // $_POST and make sure to santitize the input to mysql.
    
    $rfidKey     = mysql_real_escape_string($_POST['rfidKey']);

    // These settings define where the server is located, and
    // which credentials we use to connect to that server.  
    
    $server   = "localhost";
    $username = "admin";
    $password = "admin";
    
    // This is the database and table we are going to access in
    // the mysql server.
    
    $database = "playtimedb";
                     
    $insertAnim   = "INSERT INTO `animations` (`id`, `name`) VALUES (NULL, NULL);";
	
	$selectAnim = "SELECT `id` FROM `animations` ORDER BY `id` DESC LIMIT 1;";
	
	$selectFig = "SELECT `ID` FROM `figurines` WHERE `rfidKey` = '$rfidKey';";

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error()); 
    $result = mysql_query($insertAnim, $connection) or die($insertAnim."<br/><br/>".mysql_error());
    $result = mysql_query($selectAnim, $connection) or die($selectAnim."<br/><br/>".mysql_error());
	$row = mysql_fetch_array($result);
    $animID = $row['id'];
	$result = mysql_query($selectFig, $connection) or die($selectFig."<br/><br/>".mysql_error());
	$row = mysql_fetch_array($result);
	$figID = $row['ID'];
	
	$insertFigAnim = "INSERT INTO `figanims` (`figid`, `animid`) VALUES ('$figID', '$animID');";
	$result = mysql_query($insertFigAnim, $connection) or die($insertFigAnim."<br/><br/>".mysql_error());
	
	echo $animID;
	
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>