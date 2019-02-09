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
		<h3>Update Critic</h3>

			<?php if(isset($_POST['update'])): ?>
				<?php
					try {
						require __DIR__ . "/../model/database.php";
						require __DIR__ . "/../model/critic_db.php";

						$firstname = filter_input(INPUT_POST, 'firstNameUpdated');
						$lastname = filter_input(INPUT_POST, 'lastNameUpdated');
						$email = filter_input(INPUT_POST, 'emailUpdated');
						$password = filter_input(INPUT_POST, 'passwordUpdated');
						$criticID = filter_input(INPUT_POST, 'criticID');

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

		<p>Critic was updated successfully.</p>
	</main>
</body>
</html>
<?php include '../view/footer.php'; ?>
