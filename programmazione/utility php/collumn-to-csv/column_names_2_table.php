<?php
$servername = "localhost";
$username = "irpdhflz_risolvo";
$password = "11jrtnqmj09sbbgjpm96";
$dbname = "irpdhflz_risolvo";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "select * from INFORMATION_SCHEMA.COLUMNS where 1 order by COLUMN_NAME";
$result = $conn->query($sql);

$content = "";

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        $content .= "table name: \"" . $row["TABLE_NAME"]. "\",Data-type: \"" . $row["DATA_TYPE"]. "\",column name: \"" . $row["COLUMN_NAME"]. "\". ,table schema: \"" . $row["TABLE_SCHEMA"]. "\"\n";
    }
} else {
    echo "0 results";
} 

$temp = fopen("column_names.csv", "w");
fwrite($temp, $content);
fclose($temp);

$temp = 'column_names.csv';

if (file_exists($temp)) {
    header('Content-Description: File Transfer');
    header('Content-Type: application/octet-stream');
    header('Content-Disposition: attachment; filename="'.basename($temp).'"');
    header('Expires: 0');
    header('Cache-Control: must-revalidate');
    header('Pragma: public');
    header('Content-Length: ' . filesize($temp));
    readfile($temp);
    exit;
}

$conn->close();
?>