#pragma once

// Project includes
#include "../DXFramework/BaseShader.h"

class TextureShader final : public BaseShader
{
public:
    TextureShader(ID3D11Device* device, HWND hwnd);
    ~TextureShader() override;

    TextureShader(TextureShader const &other)                        = delete;
    TextureShader(TextureShader &&other) noexcept                    = delete;
    auto operator=(TextureShader const &other) -> TextureShader&     = delete;
    auto operator=(TextureShader &&other) noexcept -> TextureShader& = delete;

    void setShaderParameters(ID3D11DeviceContext* deviceContext, const XMMATRIX &world, const XMMATRIX &view, const XMMATRIX &projection);

private:
    void initShader(const wchar_t *vs, const wchar_t *ps) override;

private:
    ID3D11Buffer* matrixBuffer;
};
