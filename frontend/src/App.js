
import React from "react";
import '../../frontend/public/style.css';
import { BrowserRouter, Routes, Route } from "react-router-dom";
import LandingPage from "./pages/LandingPage";
import Greenhouse from "./pages/Greenhouse";
import Salesfloor from "./pages/Salesfloor";

const App = () => {
    return (
        <BrowserRouter>
            <div>
                <Routes>
                    <Route path="/" element={<LandingPage />} />
                    <Route path="/greenhouse" element={<Greenhouse />} />
                    <Route path="/salesfloor" element={<Salesfloor />} />
                </Routes>
            </div>
        </BrowserRouter>
    );
}

export default App;