#include "GUI.h"

void GUI::UIupdate()
{

    ImGui::GetIO().FontGlobalScale = 1.3f;

    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.0f, 0.0f, 0.05f, 0.7f);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(450, 140));
    ImGui::Begin("Info Window", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    
    ImVec4 white = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    ImVec4 green = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
    ImVec4 red = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 yellow = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

    ImGui::TextColored(white, "Player Position:");
    
    ImGui::SameLine();
    std::string xStr = std::to_string(camera.Position.x);
    std::string yStr = std::to_string(camera.Position.y);
    std::string zStr = std::to_string(camera.Position.z);
    std::string result = xStr + "," + yStr + "," + zStr;
    ImGui::TextColored(yellow, result.c_str());
    
    ImGui::NewLine();
    ImGui::TextColored(white, "Night Mode(Press N to toggle):");

    ImGui::SameLine();
    ImGui::TextColored(night ? green : red, night ? "On" : "Off");


    ImGui::NewLine();
    ImGui::TextColored(white, "NoClip(Press O to toggle):");

    ImGui::SameLine();
    ImGui::TextColored(!camera.fps ? green : red, !camera.fps ? "On" : "Off");
    
    ImGui::End();
}

void GUI::UIrender()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
