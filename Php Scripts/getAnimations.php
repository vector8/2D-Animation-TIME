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
	
	$selectAnims = "SELECT `figanims`.`animid` AS animID FROM `figurines` INNER JOIN `figanims` ON `figanims`.`figid` = `figurines`.`ID` WHERE `figurines`.`rfidKey` = '$rfidKey';";

    // o--------------------------------------------------------
    // | Access database
    // o--------------------------------------------------------

    // Connect to the server with our settings defined above.
    
    $connection = mysql_connect($server, $username, $password) or die(mysql_error());
    
    $result = mysql_select_db($database, $connection) or die(mysql_error());
    $result = mysql_query($selectAnims, $connection) or die($selectAnims."<br/><br/>".mysql_error());
	
	while ($row = mysql_fetch_array($result))
        echo $row['animID'] . "<br>";
	
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>