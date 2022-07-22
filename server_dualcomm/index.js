const express = require("express");
const path = require("path");

let app = express();
app.use(express.json());

let rgb = [255, 124, 115];

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "index.html"));
});

app.get("/retinfo", (req, res) => {
  res.send(rgb);
})

app.post("/update", (req, res) => {
  //console.log(req.body.body);
  if (JSON.stringify(rgb) == JSON.stringify(req.body)) {
    console.log("same color, aborting!");
    res.send(rgb);
    return 0;
  }

  console.log(req.body);
  rgb = req.body;

  for (let i=0;i<rgb.length;i++) {
    if (isNaN(rgb[i])) {rgb[i] = 0}
    rgb[i] = parseInt(rgb[i]);

    if (rgb[i] < 0 || rgb[i] > 255 || rgb[i] == null) {
      rgb[i] = 0;
    }
  }

  res.send(rgb);
});

app.listen(3000, () => console.log("server running"));