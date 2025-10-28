import express from 'express';
import path from 'path';
import cors from 'cors';
import { XMLHttpRequest } from 'xmlhttprequest';

const app = express();
const port = 3000;

const __dirname = path.resolve();

app.use(cors());
app.use(express.urlencoded({extended: false}));
app.use(express.json());


app.use(express.static(path.join(__dirname, 'frontend', 'public')));



app.get(/^\/(?!api).*/, (req, res) => {
  res.sendFile(path.resolve('frontend', 'public', 'index.html'));
});


app.listen(port, () => {
   console.log(`Listening on http://localhost:${port}`);
});
