#pragma once
#include "Systems/SystemComponent.h"
#include "Systems/SystemHeader.h"
#include "Shader/Buffer.h"
#include "Shader/ShaderManager.h"
#include "Component/Camera/Camera.h"

class Camera;

struct GraphicsData
{
	float clear_color[3] = {0.0f, 1.0f, 0.0f};

};

class Graphics : public SystemComponent
{
public:
	Graphics();
	~Graphics();

	void Initialize() override;
	void Update(float dt) override;
	void Shutdown();

public:
	Camera* m_camera = nullptr;

private:
	ShaderManager* _shader_manager = nullptr;
	Buffer* _buffer = nullptr;

	void Draw();

};
extern Graphics* mGRAPHICS;