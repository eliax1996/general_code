var mysql = require('mysql');
var express = require('express');

var app = express();

express.get(arg,function(a,b){
});

var con = mysql.createConnection({
  host: "localhost",
  user: "yourusername",
  password: "yourpassword"
});

con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
});