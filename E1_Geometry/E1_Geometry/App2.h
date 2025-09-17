#pragma once

// Standard include
#include <memory>

// Project includes
#include "TextureQuad.h"
#include "TextureShader.h"
#include "../DXFramework/DXF.h"

class App2 final: public BaseApplication
{
public:
    App2()           = default;
    ~App2() override = default;

    App2(App2 const &other)                        = delete;
    App2(App2 &&other) noexcept                    = delete;
    auto operator=(App2 const &other) -> App2&     = delete;
    auto operator=(App2 &&other) noexcept -> App2& = delete;

    void init(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight, Input *in, bool VSYNC, bool FULL_SCREEN) override;

    bool frame() override;

protected:
    bool render() override;
    void gui();

private:
    std::unique_ptr<TextureShader> textureShader;
    std::unique_ptr<TextureQuad> mesh;
};
