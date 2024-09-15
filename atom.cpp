#include "atom.h"
#include "imgui.h"

void InitStyle(ImGuiStyle &style)
{
    ImVec4 *colors                      = style.Colors;
    colors[ImGuiCol_FrameBg]            = ImVec4(0.16f, 0.16f, 0.17f, 1.00f);
    colors[ImGuiCol_FrameBgHovered]     = ImVec4(0.37f, 0.36f, 0.36f, 102.00f);
    colors[ImGuiCol_FrameBgActive]      = ImVec4(0.10f, 0.10f, 0.10f, 171.00f);
    colors[ImGuiCol_TitleBgActive]      = ImVec4(0.20f, 0.20f, 0.20f, 255.00f);
    colors[ImGuiCol_CheckMark]          = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_SliderGrab]         = ImVec4(0.64f, 0.64f, 0.64f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]   = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_Button]             = ImVec4(0.22f, 0.22f, 0.22f, 0.40f);
    colors[ImGuiCol_ButtonHovered]      = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
    colors[ImGuiCol_ButtonActive]       = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
    colors[ImGuiCol_Header]             = ImVec4(0.45f, 0.45f, 0.45f, 0.31f);
    colors[ImGuiCol_HeaderHovered]      = ImVec4(0.55f, 0.55f, 0.55f, 0.80f);
    colors[ImGuiCol_HeaderActive]       = ImVec4(0.09f, 0.09f, 0.09f, 1.00f);
    colors[ImGuiCol_ResizeGrip]         = ImVec4(1.00f, 1.00f, 1.00f, 0.20f);
    colors[ImGuiCol_ResizeGripHovered]  = ImVec4(0.46f, 0.46f, 0.46f, 0.67f);
    colors[ImGuiCol_ResizeGripActive]   = ImVec4(0.17f, 0.17f, 0.17f, 0.95f);
    colors[ImGuiCol_SeparatorActive]    = ImVec4(0.42f, 0.42f, 0.42f, 1.00f);
    colors[ImGuiCol_SeparatorHovered]   = ImVec4(0.50f, 0.50f, 0.50f, 0.78f);
    colors[ImGuiCol_TabHovered]         = ImVec4(0.45f, 0.45f, 0.45f, 0.80f);
    colors[ImGuiCol_TabActive]          = ImVec4(0.28f, 0.28f, 0.28f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
    colors[ImGuiCol_DockingPreview]     = ImVec4(0.51f, 0.51f, 0.51f, 0.70f);
    colors[ImGuiCol_Tab]                = ImVec4(0.21f, 0.21f, 0.21f, 0.86f);
    colors[ImGuiCol_TabUnfocused]       = ImVec4(0.15f, 0.15f, 0.15f, 0.97f);
    colors[ImGuiCol_NavHighlight]       = ImVec4(1.00f, 0.40f, 0.13f, 1.00f);
    colors[ImGuiCol_TextSelectedBg]     = ImVec4(0.45f, 1.00f, 0.85f, 0.35f);

    style.WindowRounding    = 4;
    style.FrameRounding     = 4;
    style.GrabRounding      = 3;
    style.ScrollbarSize     = 7;
    style.ScrollbarRounding = 0;
}

void DrawTitleBar(const char *title, bool &p_open)
{
    ImGuiWindow *window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return;

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    // 绘制左上角的文字
    ImGui::Text("%s", title);
    // ImGui::SameLine();
    // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

    // 计算关闭按钮位置
    float  button_padding = 5.0f;  // 关闭按钮距离边框的距离
    ImVec2 close_pos      = ImVec2(window->Pos.x + window->Size.x - ImGui::GetStyle().FramePadding.x - ImGui::GetFrameHeight() - button_padding, window->Pos.y + ImGui::GetStyle().FramePadding.y + button_padding);
    ImGui::SetCursorScreenPos(close_pos);

    // 绘制关闭按钮
    bool close_clicked = ImGui::InvisibleButton("##close_button", ImVec2(ImGui::GetFrameHeight(), ImGui::GetFrameHeight()));
    if (ImGui::IsItemHovered())
    {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);  // 更改鼠标光标
        ImGui::SetTooltip("关闭窗口");
    }

    // 绘制关闭按钮的图标（一个简单的'X'）
    ImDrawList *draw_list    = ImGui::GetWindowDrawList();
    ImVec2      close_center = ImVec2(close_pos.x + ImGui::GetFrameHeight() * 0.5f, close_pos.y + ImGui::GetFrameHeight() * 0.5f);
    float       cross_extent = ImGui::GetFrameHeight() * 0.3f * 0.7071f;
    draw_list->AddLine(ImVec2(close_center.x - cross_extent, close_center.y - cross_extent), ImVec2(close_center.x + cross_extent, close_center.y + cross_extent), IM_COL32(255, 255, 255, 255), 1.0f);
    draw_list->AddLine(ImVec2(close_center.x + cross_extent, close_center.y - cross_extent), ImVec2(close_center.x - cross_extent, close_center.y + cross_extent), IM_COL32(255, 255, 255, 255), 1.0f);

    // 如果关闭按钮被点击，将布尔值设置为 false
    if (close_clicked)
        p_open = false;
}