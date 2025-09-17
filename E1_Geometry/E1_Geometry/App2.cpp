#include "App2.h"

void App2::init(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight, Input *in, bool VSYNC, bool FULL_SCREEN)
{
    // Call super/parent init function (required!)
    BaseApplication::init(hinstance, hwnd, screenWidth, screenHeight, in, VSYNC, FULL_SCREEN);

    // Create Mesh object
    mesh = make_unique<TextureQuad>(renderer->getDevice(), renderer->getDeviceContext());

    textureShader = make_unique<TextureShader>(renderer->getDevice(), hwnd);
}

bool App2::frame()
{
    bool result;

    result = BaseApplication::frame();
    if (!result)
    {
        return false;
    }

    // Render the graphics.
    result = render();
    if (!result)
    {
        return false;
    }

    return true;
}

bool App2::render()
{
    // Clear the scene. (default blue colour)
    renderer->beginScene(0.39f, 0.28f, 0.92f, 1.0f);

    // Generate the view matrix based on the camera's position.
    camera->update();

    // Get the world, view, projection, and ortho matrices from the camera and Direct3D objects.
    XMMATRIX worldMatrix      = renderer->getWorldMatrix();
    XMMATRIX viewMatrix       = camera->getViewMatrix();
    XMMATRIX projectionMatrix = renderer->getProjectionMatrix();

    // Send geometry data (from mesh), send shader pararmeters and render geometry with set shaders
    mesh->sendData(renderer->getDeviceContext());
    textureShader->setShaderParameters(renderer->getDeviceContext(), worldMatrix, viewMatrix, projectionMatrix);
    textureShader->render(renderer->getDeviceContext(), mesh->getIndexCount());

    // Render GUI
    gui();

    // Present the rendered scene to the screen.
    renderer->endScene();

    return true;
}

void App2::gui()
{
    // Force turn off unnecessary shader stages.
    renderer->getDeviceContext()->GSSetShader(NULL, NULL, 0);
    renderer->getDeviceContext()->HSSetShader(NULL, NULL, 0);
    renderer->getDeviceContext()->DSSetShader(NULL, NULL, 0);

    // Build UI
    ImGui::Text("FPS: %.2f", timer->getFPS());
    ImGui::Checkbox("Wireframe mode", &wireframeToggle);

    // Render UI
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
