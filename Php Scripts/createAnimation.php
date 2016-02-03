<?php

    // o--------------------------------------------------------
    // | Input & Settings
    // o--------------------------------------------------------

    // These variables are sent from Unity, we access them via
    // $_POST and make sure to santitize the input to mysql.
    
    //$rfidKey     = mysql_real_escape_string($_POST['rfidKey']);

    // These settings define where the server is located, and
    // which credentials we use to connect to that server.  
    
    $server   = "localhost";
    $username = "admin";
    $password = "admin";
    
    // This is the database and table we are going to access in
    // the mysql server. In this example, we assume that we have
    // the table 'highscores' in the database 'gamedb'.
    
    $database = "playtimedb";
                     
    $insert   = "INSERT INTO `animations` (`id`, `name`) VALUES (NULL, NULL);";
	
	$select = "SELECT `id` FROM `animations` ORDER BY `id` DESC LIMIT 1;";

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
    
    while ($row = mysql_fetch_array($result))
        echo $row['id'];
  
    // Close the connection, we're done here.
    
    mysql_close($connection);
?>