#ifndef ATOM_H
#define ATOM_H

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include "imstb_truetype.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

void InitStyle(ImGuiStyle &style);

void DrawTitleBar(const char *title, bool &p_open);

#endif