<?php
// Connect to the database
$conn = new mysqli("localhost", "root", "", "shuttle_booking");

if ($conn->connect_error) {
    die("Database connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["seat_number"])) {
    $seatNumber = $_POST["seat_number"];
    
    // Update seat status in the database
    $updateQuery = "UPDATE seats SET is_booked = 1 WHERE seat_number = '$seatNumber'";
    if ($conn->query($updateQuery) === TRUE) {
        echo "Seat booked successfully";
    } else {
        echo "Error booking seat: " . $conn->error;
    }
}

// Close the database connection
$conn->close();
?>
