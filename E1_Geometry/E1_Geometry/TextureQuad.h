#pragma once

#include "../DXFramework/DXF.h"

class TextureQuad final : public BaseMesh
{
public:
    TextureQuad(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
    ~TextureQuad() override = default;

    TextureQuad(TextureQuad const &other)                        = delete;
    TextureQuad(TextureQuad &&other) noexcept                    = delete;
    auto operator=(TextureQuad const &other) -> TextureQuad&     = delete;
    auto operator=(TextureQuad &&other) noexcept -> TextureQuad& = delete;

    void sendData(ID3D11DeviceContext* deviceContext, D3D_PRIMITIVE_TOPOLOGY top = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST) override;

protected:
    void initBuffers(ID3D11Device* device) override;
};
