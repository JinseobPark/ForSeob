#pragma once
#include "TextureManager.h"
#include "Systems/Graphics/Graphics.h"
#include "Component/Component.h"

class Graphics;

class Model : public Component
{
	typedef unsigned int RenderQueue;
	typedef unsigned int Material_ID;
	typedef unsigned int Model_ID;
private:

public:
	Model();
	~Model();

	void Initialize() override;
	void Shutdown();
	void Render();

private:
	RenderQueue	m_render_queue;
	Material_ID		m_material_id;
	Model_ID			m_model_id;

};