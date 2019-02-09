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
			<h3>Customer Search</h3>
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
			require __DIR__ . "/../model/customers_db.php";
	
			$action = filter_input(INPUT_POST, 'lastNameSearched');
	
			if($action == $_POST['lastNameSearched']) {
				$customerLastName = filter_input(INPUT_POST, 'lastNameSearched');

				$customerList = get_customers_by_lastName($customerLastName);
				include('customer_list.php');
			}
		}
		catch (Exception $e) {
			echo 'Caught exception: ',  $e->getMessage(), "\n";
		}
	}
?>
<?php include '../view/footer.php'; ?>