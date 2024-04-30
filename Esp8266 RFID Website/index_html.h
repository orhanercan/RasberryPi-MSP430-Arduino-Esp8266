// index_html.h
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<style>
  body {
    background-color: peachpuff; /* Bütün arka planı DarkSalmon yapar */
    margin: 0; /* Sayfada satır aralarında boşluk olmamasını sağlar */
    font-family: Arial, sans-serif; /* Font tipini belirler */
  }
  h2 {
    background-color: Thistle;
    font-size: 1.5em; /* Başlık yazısını büyütür */
    font-weight: bold; /* Başlık yazısını kalın yapar */
    margin: 0; /* Başlık altındaki boşluğu kaldırır */
    padding: 10px; /* Başlık içi dolguyu ayarlar */
    text-align: center;
  }
  #latest-reading {
    background-color: CadetBlue; /* En son okuma işleminin arka planını mavi yapar */
    color: white;
    padding: 5px;
    margin: 0; /* En son okuma altındaki boşluğu kaldırır */
    font-weight: bold;
  }
  .log-entry {
    background-color: whitesmoke; /* Log girişlerinin arka planını kırmızı yapar */
    margin: 5px;
    padding: 5px;
    font-weight: bold;
     border-radius: 10px; /* Kenarları yuvarlak yapar */
  box-shadow: 3px 3px 10px rgba(0, 0, 0, 0.2); /* Gölgelendirme efekti ekler */
  }
</style>
</head>
<body>
<h2>RFID Okuyucu</h2>
<div id="latest-reading">
  <!-- En son okuma işlemi burada gösterilecek -->
</div>
<div id="logs">
  <!-- Log kayıtları burada gösterilecek -->
</div>
<script>
var logEntries = []; // Log kayıtlarını tutacak dizi

function updateTime() {
  var now = new Date();
  var time =now.getHours() + ":" + now.getMinutes() + ":" + now.getSeconds();
  var date = now.getDate() + "/" + (now.getMonth() + 1) + "/" + now.getFullYear();
  return time + " " + date; // Başına üç boşluk ekler
}

function updateLatestReading(newReading) {
  var latestReadingDiv = document.getElementById("latest-reading");
  latestReadingDiv.textContent = newReading + " " + updateTime(); // En son okuma işlemini ve tarih bilgisini günceller
}

function updateLogs(newLog) {
  logEntries.push(newLog + " " + updateTime()); // Yeni log'u ve tarih bilgisini diziye ekler
  if (logEntries.length > 5) {
    logEntries.shift(); // Dizideki ilk elemanı çıkarır, böylece en fazla son 5 kayıt kalır
  }
  var logsDiv = document.getElementById("logs");
  logsDiv.innerHTML = ''; // Mevcut logları temizler
  logEntries.forEach(function(log) { // Yeni log listesini oluşturur
    var logDiv = document.createElement("div");
    logDiv.className = "log-entry";
    logDiv.textContent = log;
    logsDiv.appendChild(logDiv);
  });
}

setInterval(function () {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var response = this.responseText;
      updateLatestReading(response); // En son okuma işlemini günceller
      if (!response.includes("No card detected")) {
        updateLogs(response); // Log kaydını günceller
      }
    }
  };
  xhttp.open("GET", "/rfid", true);
  xhttp.send();
}, 1000);
</script>
</body>
</html>
)=====";
