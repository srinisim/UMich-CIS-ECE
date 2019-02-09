<?php

$host    = "localhost";
$user    = "ts_user";
$pass    = "pa55word";
$db_name = "album_review";

$db =new mysqli($host, $user, $pass, $db_name);
if($db->connect_error)
{
    die("Cannot connect to database: \n"
        . $db->connect_error . "\n"
        . $db->connect_errno
    );

}

function  insertRecord(mysqli $db, array $record){
    $sql = "INSERT INTO `critics` ";
    $sql.= "( `criticID`,`firstName`, `lastName`, `email`,`password`)";
    $sql.= "VALUES ";
    $sql.= "(";
    $sql.= "'".$record['criticID']."', ";
    $sql.= "'".$record['firstName']."', ";
    $sql.= "'".$record['lastName']."', ";
    $sql.= "'".$record['email']."', ";
    $sql.= "'".$record['password']."' ";
    $sql.=");";
    $result = $db->query($sql);
    if(!$result){
        throw new Exception('Cannot insert record');
    }
    $record['criticID'] = $db->insert_id;
    return $record;
}

$record = [

    'criticID' => $_POST["criticID"],
    'firstName' => $_POST["firstName"],
    'lastName' => $_POST["lastName"],
    'email' => $_POST["email"],
    'password' => $_POST["password"]

];
$newRecord = insertRecord($db, $record);

include ('index.php');
?>
