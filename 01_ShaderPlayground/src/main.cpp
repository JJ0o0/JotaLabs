#include <platform/window.hpp>
#include <platform/imgui_handler.hpp>
#include <graphics/shader.hpp>
#include <graphics/shader_uniforms.hpp>
#include <graphics/mesh.hpp>
#include <graphics/shapes/sphere.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <camera.hpp>
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>

void renderGUI(ShaderUniforms& uniforms) {
    ImGui::SetNextWindowSize(ImVec2{ 280, 60});
    ImGui::Begin("Settings", nullptr, 
        ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoTitleBar
    );

    ImGui::ColorEdit3("Color", glm::value_ptr(uniforms.Color));
    ImGui::SliderFloat("Intensity", &uniforms.Intensity, 0.0f, 1.0f, "%.2f");
    ImGui::End();
}

int main() {
    Window window{};

    ImGuiHandler imgui{};
    imgui.Init(window.GetHandle());

    Camera camera{};

    Shader shader{"assets/shaders/default.vert", "assets/shaders/default.frag"};
    ShaderUniforms shaderUniforms{};
    Mesh mesh = CreateSphere();

    window.WasKeyPressed = [&](int key) {
        switch (key) {
            case GLFW_KEY_ESCAPE: window.Close(); break;
            case GLFW_KEY_R: shader.ChangeFragment("assets/shaders/default.frag"); break;
        }
    };

    window.OnMouseMove = [&](double xpos, double ypos) {
        camera.HandleMouseMovement(xpos, ypos);
    };

    glm::mat4 model{1.0f};

    float lastTime = glfwGetTime();
    while (!window.ShouldClose()) {
        float currTime = glfwGetTime();
        float deltaTime = currTime - lastTime;
        lastTime = currTime;

        shaderUniforms.Time = currTime;

        window.PollEvents();

        camera.HandleMovementInput(window.GetHandle(), deltaTime);
        camera.HandleMouseInput(window.GetHandle());

        glClearColor(0.1f, 0.1f, 0.13f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.Bind();
            shaderUniforms.Apply(shader);
            shader.SetMat4("uModel", model);
            shader.SetMat4("uView", camera.GetViewMatrix());
            shader.SetMat4("uProjection", camera.GetProjectionMatrix());

            mesh.Draw();
        shader.Unbind();

        imgui.Begin();
            renderGUI(shaderUniforms);
        imgui.End();

        window.SwapBuffers();
    }

    imgui.Destroy();

    return 0;
}