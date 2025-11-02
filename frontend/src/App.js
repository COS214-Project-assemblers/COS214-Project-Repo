
import React from "react";
import "./style.css";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import LandingPage from "./pages/LandingPage";
import Greenhouse from "./pages/Greenhouse";
import Salesfloor from "./pages/Salesfloor";
import Tutorial from "./pages/Tutorial";
import GameOver from "./pages/GameOver";
import EndOfDay from "./pages/EndOfDay";

const App = () => {
    return (
        <BrowserRouter>
            <div>
                <Routes>
                    <Route path="/" element={<LandingPage />} />
                    <Route path="/greenhouse" element={<Greenhouse />} />
                    <Route path="/salesfloor" element={<Salesfloor />} />
                    <Route path="/tutorial" element={<Tutorial />} />
                    <Route path="/gameover" element={<GameOver />} />
                    <Route path="/endofday" element={<EndOfDay />} />
                </Routes>
            </div>
        </BrowserRouter>
    );
}

export default App;