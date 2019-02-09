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
		<h3>Register Product</h3>

		<?php if(isset($_POST['selectedProduct'])): ?>
			<?php 
				try {
					require __DIR__ . "/../model/database.php";
					require __DIR__ . "/../model/registrations_db.php";

					$productName = $_POST['selectedProduct'];
					$productCode = get_productCodes_by_productName($productName);
					$currentDate = date('Y-m-d');

					session_start();
					$customerID = $_SESSION['customerID'];

					// echo "Product Code is " . $productCode['productCode'] . ".<br>";
					// echo "Customer is " . $customerID . ".<br>";
					// echo "Current Date is " . $currentDate . ".";

					insert_registrations($productCode['productCode'], $customerID, $currentDate);
				}
				catch (Exception $e) {
					echo 'Caught exception: ',  $e->getMessage(), "\n";
				}
			?>
		<?php endif; ?>

		<p>Product (<?php echo $productCode['productCode'] ?>) was registered successfully.</p>
	</main>
</body>
</html>
<?php include '../view/footer.php'; ?>