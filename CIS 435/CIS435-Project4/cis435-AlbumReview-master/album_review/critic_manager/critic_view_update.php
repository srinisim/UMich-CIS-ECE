<?php include '../view/header.php'; ?>

<!DOCTYPE <!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<!-- <title>Page Title</title> -->
		<link rel="stylesheet" type="text/css" href="../main.css" />
	</head>
	<body>
		<main>
			<?php if (isset($_POST['criticID'])): ?>
				<?php
					try {
						require __DIR__ . "/../model/database.php";
						require __DIR__ . "/../model/critic_db.php";

						$criticID =  filter_input(INPUT_POST, 'criticID');

						session_start();
						$_SESSION["critic_ID"] = $criticID;

						$critic = get_critic_by_id($criticID);
					}
					catch (Exception $e) {
						echo 'Caught exception: ',  $e->getMessage(), "\n";
					}
				?>

				<form id="aligned" action=<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?> method="post">
				<!-- <form id="aligned" action="critic_successful.php"> method="post"> -->
					<label for="firstNameUpdated">First Name: </label>
					<input type="text" name="firstNameUpdated" value="<?php echo $critic['firstName'] ?>"><br>

					<label for="lastNameUpdated">Last Name: </label>
					<input type="text" name="lastNameUpdated" value="<?php echo $critic['lastName'] ?>"><br>

					<label for="emailUpdated">Email: </label>
					<input type="text" name="emailUpdated" value="<?php echo $critic['email'] ?>"><br>

					<label for="passwordUpdated">Password: </label>
					<input type="text" name="passwordUpdated" value="<?php echo $critic['password'] ?>"><br>

					<input type="submit" name= "update" value="Update Critic">
				</form>
			<?php endif; ?>

			<?php if(isset($_POST['update'])): ?>
				<?php
					try {
						require __DIR__ . "/../model/database.php";
						require __DIR__ . "/../model/critic_db.php";

						$firstname = filter_input(INPUT_POST, 'firstNameUpdated');
						$lastname = filter_input(INPUT_POST, 'lastNameUpdated');
						$email = filter_input(INPUT_POST, 'emailUpdated');
						$password = filter_input(INPUT_POST, 'passwordUpdated');

						session_start();
						$criticID = $_SESSION["critic_ID"];

						update_critic_by_id($firstname, $lastname, $email, $password, $criticID);

						// echo "<p>Updated</p>";
						// echo "<p>$firstname</p>";
						// echo "<p>$lastname</p>";
						// echo "<p>$address</p>";
						// echo "<p>$city</p>";
						// echo "<p>$state</p>";
						// echo "<p>$postalcode</p>";
						// echo "<p>$countrycode</p>";
						// echo "<p>$phone</p>";
						// echo "<p>$email</p>";
						// echo "<p>$password</p>";
						// echo "<p>$criticID</p>";
					}
					catch (Exception $e) {
						echo 'Caught exception: ',  $e->getMessage(), "\n";
					}
				?>
			<?php endif; ?>

			<a href="index.php">Search Critics</a>
		</main>
	</body>
</html>

<?php include '../view/footer.php'; ?>
