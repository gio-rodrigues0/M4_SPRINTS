
#include <WiFi.h>
#include <WebServer.h>
#include <ESP2SOTA.h>

#define led1 1
#define led2 2

const char* ssid = "Inteli-COLLEGE";
const char* password = "QazWsx@123";

WebServer server(80);

String handleRoot() {
 String HTML = "<!DOCTYPE html>";
 HTML += "<html lang=\"en\">";
 HTML += "<head>";
 HTML += "<meta charset=\"UTF-8\">";
 HTML += "<title>Jogo da Memória</title>";
 HTML += "</head>";

 HTML += "<body>";
 HTML += "<div class=\"Memory\">";
 HTML += "<h2>Memory <span id=\"memoryID\"></span></h2>";
 HTML += "<button class=\"restartbutton\" onClick=\"window.location.reload();\">Restart Game</button>";
 HTML += "</div>";
 HTML += "<div class=\"frame169\">";
 HTML += "<h1> 1 </h1>";
 HTML += "<div class=\"Player1\" data-id=\"P1\">";
 HTML += "<h2>Player 1</h2>";
 HTML += "<h2>Score:   <span id=\"score1\"></span></h2>";
 HTML += "</div>";
 HTML += "</div>";
 HTML += "<section class=\"board\">";
 HTML += "<div class=\"card\" data-id=\"2b\">";
 HTML += "<h1 class=\"ff\">Sérgio</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"2b\">";
 HTML += "<h1 class=\"ff\">Sérgio</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"2r\">";
 HTML += "<h1 class=\"ff\">Egon</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"2r\">";
 HTML += "<h1 class=\"ff\">Egon</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"3b\">";
 HTML += "<h1 class=\"ff\">Hayashi</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"3b\">";
 HTML += "<h1 class=\"ff\">Hayashi</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"3r\">";
 HTML += "<h1 class=\"ff\">Fátima</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"3r\">";
 HTML += "<h1 class=\"ff\">Fátima</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"4b\">";
 HTML += "<h1 class=\"ff\">G4</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "<div class=\"card\" data-id=\"4b\">";
 HTML += "<h1 class=\"ff\">G4</h1>";
 HTML += "<h1 class=\"bb\"/>?</h1>";
 HTML += "</div>";
 HTML += "</section>";
 HTML += "<div class=\"frame170\">";
 HTML += "<h1> 2 </h1>";
 HTML += "<div class=\"Player2\" data-id=\"P2\">";
 HTML += "<h2>Player 2</h2>";
 HTML += "<h2>Score: <span id=\"score2\"></span></h2>";
 HTML += "</div>";
 HTML += "</div>";

 HTML += "<style>";
 HTML += "*{";
 HTML += "padding: 20;";
 HTML += "margin: 0;";
 HTML += "box-sizing: border-box;";
 HTML += "}";

 HTML += "body{";
 HTML += "background: #3E92CE;";
 HTML += "display: flex;";
 HTML += "filter: blur(0.1px);";
 HTML += "}";

 HTML += ".board{";
 HTML += "position: relative;";
 HTML += "width: 842px;";
 HTML += "height: 844px;";
 HTML += "top: 100px;";
 HTML += "display: flex;";
 HTML += "flex-wrap: wrap;";
 HTML += "margin: auto;";
 HTML += "background: linear-gradient(133.05deg, rgba(255, 255, 255, 0.6) 0.62%, rgba(255, 255, 255, 0.1) 102.4%);";
 HTML += "border-radius: 8px;";
 HTML += "}";

 HTML += ".card\{";
 HTML += "width: calc(20%);";
 HTML += "height: calc(25%);";
 HTML += "position: relative;";
 HTML += "margin: 5px;";
 HTML += "transform: scale(1);";
 HTML += "transform-style: preserve-3d;";
 HTML += "transition: transform .5s;";
 HTML += "}";

 HTML += ".card\:active{";
 HTML += "transform: scale(.97);";
 HTML += "transition: transform .2s;";
 HTML += "}";

 HTML += ".card\.flip{";
 HTML += "transform: rotateY(180deg);";
 HTML += "}";

 HTML += ".ff\, .bb\{ /*front face and back face*/";
 HTML += "position: absolute;";
 HTML += "width: 100%;";
 HTML += "height: 100%;"; 
 HTML += "padding: 20px;";
 HTML += "border-radius: 5px;";
 HTML += "backface-visibility: hidden;"; 
 HTML += "}";

 HTML += ".ff\{";
 HTML += "transform: rotateY(180deg);";
 HTML += "}";

 HTML += ".Memory{";
 HTML += "position: absolute;";
 HTML += "width: 182px;";
 HTML += "height: 40px;";
 HTML += "left: 535px;";
 HTML += "top: 32px;";
 HTML += "font-family: Poppins;";
 HTML += "font-style: normal;";
 HTML += "font-weight: bold;";
 HTML += "font-size: 40.187px;";
 HTML += "line-height: 40px;";
 HTML += "letter-spacing: 0.0882153px;";
 HTML += "color: #FFFFFF;";
 HTML += "}";

 HTML += ".restartbutton{";
 HTML += "text-align: center;";
 HTML += "padding: 16px;";
 HTML += "font-size: 18px;";
 HTML += "border: #f4a236;";
 HTML += "color: #ffffff;";
 HTML += "position: absolute;";
 HTML += "width: 160px;";
 HTML += "height: 52px;";
 HTML += "left: 528px;";
 HTML += "top: 5px;";
 HTML += "line-height: 20px;";
 HTML += "transform: scale(1);";
 HTML += "transform-style: preserve-3d;";
 HTML += "transition: transform .5s;";
 HTML += "background: #F4A236;";
 HTML += "border-radius: 8px;";
 HTML += "}";

 HTML += ".restartbutton:active, .exitbutton:active{";
 HTML += "transform: scale(.97);";
 HTML += "transition: transform .2s;";
 HTML += "}";

 HTML += ".Player1, .Player2{";
 HTML += "position: relative;";
 HTML += "width: 100px;";
 HTML += "height: 36px;";
 HTML += "left: -30px;";
 HTML += "top: 30px;";
 HTML += "font-family: Poppins;";
 HTML += "font-style: normal;";
 HTML += "font-weight: 800;";
 HTML += "font-size: 14px;";
 HTML += "line-height: 36px;";
 HTML += "text-align: left;";
 HTML += "letter-spacing: -0.02em;";
 HTML += "text-transform: capitalize;";
 HTML += "color: #FFFFFF;";
 HTML += "}";

 HTML += ".frame169{";
 HTML += "display: flex;";
 HTML += "flex-direction: column;";
 HTML += "align-items: center;";
 HTML += "padding: 28px;";
 HTML += "position: absolute;";
 HTML += "width: 100px;";
 HTML += "height: 150px;";
 HTML += "left: 50px;";
 HTML += "top: 250px;";
 HTML += "border-radius: 8px;";
 HTML += "}";

 HTML += ".frame170{";
 HTML += "display: flex;";
 HTML += "flex-direction: column;";
 HTML += "align-items: center;";
 HTML += "padding: 28px;";
 HTML += "position: absolute;";
 HTML += "width: 220px;";
 HTML += "height: 344px;";
 HTML += "right: 0px;";
 HTML += "top: 250px;";
 HTML += "border-radius: 8px;";
 HTML += "}";
 HTML += "</style>";

 HTML += "<script>";
 HTML += "const deck = document.querySelectorAll('.card');";
 HTML += "deck.forEach(card => card.addEventListener('click', flipCard));";

 HTML += "shuffleDeck();"; // randomizes the board before each game

 HTML += "const displayScore1 = document.querySelector('#score1');";
 HTML += "const displayScore2 = document.querySelector('#score2');";
 HTML += "let gameOverMsg = document.querySelector('#memoryID');";

 HTML += "let score1 = 0;";
 HTML += "let score2 = 0;";
 HTML += "let isFirstCard = false;";
 HTML += "let first, second;";
 HTML += "let isBoardClosed = false;";
 HTML += "let p1Turn = true;";

 HTML += "function shuffleDeck(){";
 HTML += "debugger";
 HTML += "deck.forEach(card => {";
 HTML += "randomIndex = Math.floor(Math.random()*54);";
 HTML += "card.style.order = randomIndex;";
 HTML += "});";
 HTML += "}";


 HTML += "function flipCard(){";
 HTML += "if (isBoardClosed) return;";
 HTML += "if (this === first) return;";
    
 HTML += "this.classList.add('flip');";

 HTML += "if (!isFirstCard){";
 HTML += "isFirstCard = true;"; //first click
 HTML += "first = this;"; // 'this' = the element that has fired the event
 HTML += "return";
 HTML += "}";
       
 HTML += "isFirstCard = false;"; //second click
 HTML += "second = this;";

 HTML += "checkMatch();";
 HTML += "}";

 HTML += "function checkMatch(){";

 HTML += "if (first.dataset.id == second.dataset.id) {";
 HTML += "first.removeEventListener('click', flipCard);";
 HTML += "second.removeEventListener('click', flipCard);";
 HTML += "removeCards(first,second);";

 HTML += "resetBoard();";

 HTML += "if (p1Turn) {";
 HTML += "score1 +=2;";
 HTML += "displayScore1.textContent = score1.toString();";
 HTML += "}";
 HTML += "else {";
 HTML += "score2 +=2;";
 HTML += "displayScore2.textContent = score2.toString();";
 HTML += "}";
 HTML += "checkGameOver();";
 HTML += "}"; 
 HTML += "else{";
 HTML += "isBoardClosed = true;";
 HTML += "setTimeout(() => {";
 HTML += "first.classList.remove('flip');";
 HTML += "second.classList.remove('flip');";
 HTML += "isBoardClosed = false;";
 HTML += "resetBoard();";
 HTML += "}, 1000);";
 HTML += "if (p1Turn){";
 HTML += "p1Turn = false;";
 HTML += "}";
 HTML += "else if (!p1Turn){";
 HTML += "p1Turn = true;";
 HTML += "}";
 
 HTML += "}";
 HTML += "}";

 HTML += "/**";
 HTML += "* Removes correctly found matching cards from the board";
 HTML += "* @param {*} first"; 
 HTML += "* @param {*} second /";
 HTML += "*/";

 HTML += "function removeCards(first, second){";
 HTML += "setTimeout(() => {";
 HTML += "first.innerHTML = \"\";";
 HTML += "first.style.backgroundImage = \"\none\";";
 HTML += "first.style.backgroundColor = \"transparent\";";
 HTML += "second.innerHTML = \"\";";
 HTML += "second.style.backgroundImage = \"none\";";
 HTML += "second.style.backgroundColor = \"transparent\";";
        
 HTML += "}, 600);";
 HTML += "}";

 HTML += "function resetBoard(){";
 HTML += "first = null;";
 HTML += "second = null;";
 HTML += "isFirstCard = false;";
 HTML += "isBoardClosed = false;";
 HTML += "}";

 HTML += "function restartGame(){";
 HTML += "shuffleDeck();";

 HTML += "}";

 HTML += "function checkGameOver(){"; // game is over if either player gets 28 points
 HTML += "if (score1 === 6){";
 HTML += "alert(\"CONGRATULATIONS PLAYER ONE! YOU WON!\");";
 HTML += "document.location = '/win1';";

 HTML += "shuffleDeck();";
 HTML += "location.reload();";
 HTML += "}";
 HTML += "else if (score2 === 6){";
 HTML += "alert(\"CONGRATULATIONS PLAYER TWO! YOU WON!\");";
 HTML += "document.location = '/win2';";
 HTML += "shuffleDeck();";
 HTML += "location.reload();";
 HTML += "}";
 HTML += "}";
 HTML += "</script>";

 HTML += "</body>";
 HTML += "</html>";
 return HTML;
}

void win1(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  delay(5000);
  digitalWrite(led1, LOW);
}

void win2(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led2, HIGH);
  delay(5000);
  digitalWrite(led2, LOW);
}

void initWiFi() {
  Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(300);
      Serial.print(".");
    }
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  initWiFi();

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", handleRoot());
  });

  server.on("/win1", win1);
  server.on("/win2", win2);

  ESP2SOTA.begin(&server);
  server.begin();
}

void loop() {
  server.handleClient();
  delay(5);
}



