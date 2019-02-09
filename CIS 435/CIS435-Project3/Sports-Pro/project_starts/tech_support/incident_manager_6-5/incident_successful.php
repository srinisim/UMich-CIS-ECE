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
		<h3>Create Incident</h3>

		<?php if(isset($_POST['incident'])): ?>
			<?php 
				try {
					require __DIR__ . "/../model/database.php";
					require __DIR__ . "/../model/incidents_db.php";

					session_start();

					$customerID = $_SESSION['customerID'];
					$productCode = get_productCodes_by_productName($_POST['selectedProduct']);
					$dateOpened = date('Y-m-d');
					$title = $_POST['title'];
					$description = $_POST['description'];

					insert_incidents($customerID, $productCode['productCode'], $dateOpened, $title, $description);
				}
				catch (Exception $e) {
					echo 'Caught exception: ',  $e->getMessage(), "\n";
				}
			?>
		<?php endif; ?>

		<p>This incident was added to our database.</p>
	</main>
</body>
</html>
<?php include '../view/footer.php'; ?>