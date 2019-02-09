<?php include '../view/header.php'; ?>
<!DOCTYPE <!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<!-- <title>Page Title</title> -->
		<link rel="stylesheet" type="text/css" media="screen" href="../main.css" />
	</head>
	<body>
		<main>
			<h3>Critic Search</h3>
			<form action=<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?> method="post">
				<label for="lastNameSearched">Last Name: </label>
				<input type="text" name="lastNameSearched">
				<input type="submit" value="Search">
			</form>
		</main>
	</body>
</html>
<?php
	if(isset($_POST['lastNameSearched'])) {
		try {
			require __DIR__ . "/../model/database.php";
			require __DIR__ . "/../model/critic_db.php";

			$action = filter_input(INPUT_POST, 'lastNameSearched');
=======
<?php include "../view/header.php" ?>


<?php
$host    = "localhost";
$user    = "ts_user";
$pass    = "pa55word";
$db_name = "tech_support";

$db =new mysqli($host, $user, $pass, $db_name);
if($db->connect_error)
{
    die("Cannot connect to database: \n"
        . $db->connect_error . "\n"
        . $db->connect_errno
    );

}

function fetchAll(mysqli $db)
{
    $data = [];

    $sql = 'SELECT * FROM critics';

    $results = $db->query($sql);

    if ($results->num_rows > 0) {
        while ($row = $results->fetch_object()) {
            $data[] = $row;
        }
    }
    return $data;
}

$records = fetchAll($db);
>>>>>>> a5069105ce67c647e98a12b6847f9257a08a8071

			if($action == $_POST['lastNameSearched']) {
				$criticLastName = filter_input(INPUT_POST, 'lastNameSearched');

				$criticList = get_critics_by_lastName($criticLastName);
				include('critic_list.php');
			}
		}
		catch (Exception $e) {
			echo 'Caught Exception: ',  $e->getMessage(), "\n";
		}
	}
?>
<?php include '../view/footer.php'; ?>
