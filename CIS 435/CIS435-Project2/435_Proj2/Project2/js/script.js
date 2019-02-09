"use strict";

var count = 0;
var hrs = 0;
var mins = 0;
var secs = 0;

var pvpTurn = Math.floor(Math.random() * (1 - 0 + 1)) + 0;
var pvcTurn = Math.floor(Math.random() * (1 - 0 + 1)) + 0;
var whoPlaying = "", timex = "", pvp = false, pvc = false, resetTime = false;
var isGameWon = false, isGameDrawn = false, isGameOver = false, count = 0;

var $ = function(id){
    return document.getElementById(id);
}

var startGame = function(){
    isGameOver = false;
    enableAllCells(); currentGameSetting();
    $('hours').innerHTML = '00:'; $('mins').innerHTML = '00:'; $('secs').innerHTML = "00";
    $("gamesPlayed").innerHTML = "Games Played: " + count;
    startTimer();
}

var reset = function(){
    $("playAgainBtn").style.display = 'none';
    $("playerTurn").style.display = 'initial';
    isGameWon = false, isGameDrawn = false, count++;
    $("gamesPlayed").innerHTML = "Games Played: " + count;

    // clear cell innerHTML
    $("square1").innerHTML = "", $("square2").innerHTML = "", $("square3").innerHTML = "";
    $("square4").innerHTML = "", $("square5").innerHTML = "", $("square6").innerHTML = "";
    $("square7").innerHTML = ""; $("square8").innerHTML = "", $("square9").innerHTML = "";

    //enable cell pointerEvents
    enableAllCells();

    //resetTimer
    isGameOver = false; resetTime = true;
    hrs = 0, mins = 0, secs = 0;
    $('hours').innerHTML = '00:'; $('mins').innerHTML = '00:'; $('secs').innerHTML = "00";
    startTimer();
}

function currentGameSetting(){
    if($("pVc").checked){
        $("playerTurn").innerHTML = "";
        playerVcomp();
    }else if($("pVp").checked){
        pvp = true;
        playerVplayer();
    }
}

//used to toggle between X player and O player
function togglePlayer(){
    let letter = "";
    if(pvpTurn == 1){
        $("playerTurn").innerHTML = "It is X's turn";
        pvpTurn = 0;
        letter = 'X';
        return letter;
    } else if(pvpTurn == 0){
        $("playerTurn").innerHTML = "It is O's turn";
        pvpTurn = 1;
        letter = 'O';
        return letter;
    }
}

function playerVplayer(){
    if(pvp)
        whoPlaying = togglePlayer();

    $("square1").addEventListener("click", function(){$("square1").innerHTML = whoPlaying; checkForWinner(); $("square1").style.pointerEvents = 'none';});
    $("square2").addEventListener("click", function(){$("square2").innerHTML = whoPlaying; checkForWinner(); $("square2").style.pointerEvents = 'none';});
    $("square3").addEventListener("click", function(){$("square3").innerHTML = whoPlaying; checkForWinner(); $("square3").style.pointerEvents = 'none';});
    $("square4").addEventListener("click", function(){$("square4").innerHTML = whoPlaying; checkForWinner(); $("square4").style.pointerEvents = 'none';});
    $("square5").addEventListener("click", function(){$("square5").innerHTML = whoPlaying; checkForWinner(); $("square5").style.pointerEvents = 'none';});
    $("square6").addEventListener("click", function(){$("square6").innerHTML = whoPlaying; checkForWinner(); $("square6").style.pointerEvents = 'none';});
    $("square7").addEventListener("click", function(){$("square7").innerHTML = whoPlaying; checkForWinner(); $("square7").style.pointerEvents = 'none';});
    $("square8").addEventListener("click", function(){$("square8").innerHTML = whoPlaying; checkForWinner(); $("square8").style.pointerEvents = 'none';});
    $("square9").addEventListener("click", function(){$("square9").innerHTML = whoPlaying; checkForWinner(); $("square9").style.pointerEvents = 'none';});
}

function playerVcomp(){
    if(pvcTurn == 1){
        checkForWinner();
    } else if(pvcTurn == 0){
        checkForEmptyCells();
        checkForWinner();
        pvcTurn = 1;
        currentGameSetting();
    }
}

//print X only for pvc
function printOnlyX(){
    $("square1").addEventListener("click", function(){if($("pVp").checked) return; $("square1").innerHTML = 'X'; $("square1").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square2").addEventListener("click", function(){if($("pVp").checked) return; $("square2").innerHTML = 'X'; $("square2").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square3").addEventListener("click", function(){if($("pVp").checked) return; $("square3").innerHTML = 'X'; $("square3").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square4").addEventListener("click", function(){if($("pVp").checked) return; $("square4").innerHTML = 'X'; $("square4").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square5").addEventListener("click", function(){if($("pVp").checked) return; $("square5").innerHTML = 'X'; $("square5").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square6").addEventListener("click", function(){if($("pVp").checked) return; $("square6").innerHTML = 'X'; $("square6").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square7").addEventListener("click", function(){if($("pVp").checked) return; $("square7").innerHTML = 'X'; $("square7").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square8").addEventListener("click", function(){if($("pVp").checked) return; $("square8").innerHTML = 'X'; $("square8").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
    $("square9").addEventListener("click", function(){if($("pVp").checked) return; $("square9").innerHTML = 'X'; $("square9").pointerEvents = 'none'; pvcTurn = 0; checkForWinner(); if(!isGameOver) checkForEmptyCells();});
}

function checkForEmptyCells(){
    let rNmumber = Math.floor((Math.random() * 9) + 1);

    var spot1 = $("square1").innerHTML, sqr2 = $("square2").innerHTML, sqr3 = $("square3").innerHTML;
    var sqr4 = $("square4").innerHTML, sqr5 = $("square5").innerHTML, sqr6 = $("square6").innerHTML;
    var sqr7 = $("square7").innerHTML, sqr8 = $("square8").innerHTML, sqr9 = $("square9").innerHTML;

    if(rNmumber == 1 && sqr1 == ""){
        $("square1").innerHTML = "O"; checkForWinner(); $("square1").pointerEvents = 'none';
    } else if(rNmumber == 2 && sqr2 == ""){
        $("square2").innerHTML = "O"; checkForWinner(); $("square2").pointerEvents = 'none';
    } else if(rNmumber == 3 && sqr3 == ""){
        $("square3").innerHTML = "O"; checkForWinner(); $("square3").pointerEvents = 'none';
    } else if(rNmumber == 4 && sqr4 == ""){
        $("square4").innerHTML = "O"; checkForWinner(); $("square4").pointerEvents = 'none';
    } else if(rNmumber == 5 && sqr5 == ""){
        $("square5").innerHTML = "O"; checkForWinner(); $("square5").pointerEvents = 'none';
    } else if(rNmumber == 6 && sqr6 == ""){
        $("square6").innerHTML = "O"; checkForWinner(); $("square6").pointerEvents = 'none';
    } else if(rNmumber == 7 && sqr7 == ""){
        $("square7").innerHTML = "O"; checkForWinner(); $("square7").pointerEvents = 'none';
    } else if(rNmumber == 8 && sqr8 == ""){
        $("square8").innerHTML = "O"; checkForWinner(); $("square8").pointerEvents = 'none';
    } else if(rNmumber == 9 && sqr9 == ""){
        $("square9").innerHTML = "O"; checkForWinner(); $("square9").pointerEvents = 'none';
    } else{ checkForEmptyCells();}

    // checkForWinner();
    pvcTurn = 1;
}

function isWonOrDrawn(winner){
    isGameOver = true;
    if(isGameWon){
        alert("Player " + winner + " has won the match!");
        disableAllCells();
        $("playerTurn").style.display = 'none';
        $("playAgainBtn").style.display = 'initial';
    } else if(isGameDrawn){
        alert("It's a tie!");
        disableAllCells();
        $("playerTurn").style.display = 'none';
        $("playAgainBtn").style.display = 'initial';
    }
}

//checks rows, cols, and diags to determine winner
function checkForWinner(){
    if (isGameOver)
        return;

    var sqr1 = $("square1").innerHTML, sqr2 = $("square2").innerHTML, sqr3 = $("square3").innerHTML;
    var sqr4 = $("square4").innerHTML, sqr5 = $("square5").innerHTML, sqr6 = $("square6").innerHTML;
    var sqr7 = $("square7").innerHTML, sqr8 = $("square8").innerHTML, sqr9 = $("square9").innerHTML;

    //check rows for win
    if(((sqr1=="X") || (sqr1=="O")) && ((sqr1 == sqr2) && (sqr2 == sqr3))){
        isGameWon = true; isWonOrDrawn(sqr1);
    } else if(((sqr4=="X") || (sqr4=="O")) && ((sqr4 == sqr5) && (sqr5 == sqr6))){
        isGameWon = true; isWonOrDrawn(sqr4);
    } else if(((sqr7=="X") || (sqr7=="O")) && ((sqr7 == sqr8) && (sqr8 == sqr9))){
        isGameWon = true; isWonOrDrawn(sqr7);
    }
    //check cols for win
    else if(((sqr1=="X") || (sqr1=="O")) && ((sqr1 == sqr4) && (sqr4 == sqr7))){
        isGameWon = true; isWonOrDrawn(sqr1);
    } else if(((sqr2=="X") || (sqr2=="O")) && ((sqr2 == sqr5) && (sqr5 == sqr8))){
        isGameWon = true; isWonOrDrawn(sqr2);
    } else if(((sqr3=="X") || (sqr3=="O")) && ((sqr3 == sqr6) && (sqr6 == sqr9))){
        isGameWon = true; isWonOrDrawn(sqr3);
    }
    //check diags for winner
    else if(((sqr1=="X") || (sqr1=="O")) && ((sqr1 == sqr5) && (sqr5 == sqr9))){
        isGameWon = true; isWonOrDrawn(sqr1);
    } else if(((sqr3=="X") || (sqr3=="O")) && ((sqr3 == sqr5) && (sqr5 == sqr7))){
        isGameWon = true; isWonOrDrawn(sqr3);
    }
    //draw
    else if(sqr1 != "" && sqr2 != "" && sqr3 != "" && sqr4 != "" && sqr5 != "" &&
            sqr6 != "" && sqr7 != "" && sqr8 != "" && sqr9 != ""){
        isGameDrawn = true; isWonOrDrawn(sqr1);
    }
}

function disableAllCells() {
    $("square1").style.pointerEvents = 'none', $("square2").style.pointerEvents = 'none', $("square3").style.pointerEvents = 'none';
    $("square4").style.pointerEvents = 'none', $("square5").style.pointerEvents = 'none', $("square6").style.pointerEvents = 'none';
    $("square7").style.pointerEvents = 'none', $("square8").style.pointerEvents = 'none', $("square9").style.pointerEvents = 'none';
}

function enableAllCells(){
    $("square1").style.pointerEvents = "all"; $("square2").style.pointerEvents = "all"; $("square3").style.pointerEvents = "all";
    $("square4").style.pointerEvents = "all"; $("square5").style.pointerEvents = "all"; $("square6").style.pointerEvents = "all";
    $("square7").style.pointerEvents = "all"; $("square8").style.pointerEvents = "all"; $("square9").style.pointerEvents = "all";
}

function startTimer(){
    if (isGameOver){return;}

    if (resetTime){ clearTimeout(timex);}

    timex = setTimeout(function(){
        secs++;
        if(secs > 59){
            secs = 0;
            mins++;
            if(mins > 59){
                mins = 0;
                hrs++;
                if(hrs < 10){
                    $('hours').innerHTML = "0"+ hrs + ":";
                }else{
                    $('hours').innerHTML = hrs + ":";
                }
            }
            if(mins < 10){
                $('mins').innerHTML = "0"+ mins + ":";
            }else{
                $('mins').innerHTML = mins + ":";
            }
        }
        if(secs < 10){
            $('secs').innerHTML = "0"+ secs;
        }else{
            $('secs').innerHTML = secs;
        }
        startTimer();
    }, 1000);
}

window.onload = function(){
    disableAllCells(); printOnlyX();
    $("startBtn").onclick = startGame;
    $("startBtn").ondblclick = reset;
    $("playAgainBtn").onclick = reset;
}
