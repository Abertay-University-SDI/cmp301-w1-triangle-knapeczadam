#pragma once

#include "../DXFramework/DXF.h"

class ColourQuad final : public BaseMesh
{
public:
    ColourQuad(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
    ~ColourQuad() override = default;

    ColourQuad(ColourQuad const &other)                        = delete;
    ColourQuad(ColourQuad &&other) noexcept                    = delete;
    auto operator=(ColourQuad const &other) -> ColourQuad&     = delete;
    auto operator=(ColourQuad &&other) noexcept -> ColourQuad& = delete;

    void sendData(ID3D11DeviceContext* deviceContext, D3D_PRIMITIVE_TOPOLOGY top = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST) override;

protected:
    void initBuffers(ID3D11Device* device) override;
};
