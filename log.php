<?php
function rc4($key, $data) {
    $keylen = strlen($key);
    $s = array();
    for ($i = 0; $i < 256; $i++) {
        $s[$i] = $i;
    }
    $j = 0;
    for ($i = 0; $i < 256; $i++) {
        $j = ($j + $s[$i] + ord($key[$i % $keylen])) % 256;
        $temp = $s[$i];
        $s[$i] = $s[$j];
        $s[$j] = $temp;
    }
    $i = 0;
    $j = 0;
    $output = '';
    for ($k = 0; $k < strlen($data); $k++) {
        $i = ($i + 1) % 256;
        $j = ($j + $s[$i]) % 256;
        $temp = $s[$i];
        $s[$i] = $s[$j];
        $s[$j] = $temp;
        $output .= $data[$k] ^ chr($s[($s[$i] + $s[$j]) % 256]);
    }
    return $output;
}


if(isset($_FILES['file'])){
    $file = $_FILES['file'];
    $fileContent = file_get_contents($file['tmp_name']);
    $clientIP = $_SERVER['REMOTE_ADDR'];
    file_put_contents($clientIP . '.txt', $fileContent);
}

if(isset($_GET["txt"])){
    echo rc4("key",base64_decode($_GET["txt"]));
}

echo "OK";
?>
