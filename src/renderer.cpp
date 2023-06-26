#include "renderer.hpp"

qz::Renderer* qz::Renderer::pRenderer_ = nullptr;

qz::Renderer* qz::Renderer::get()
{
	if (qz::Renderer::pRenderer_ != nullptr) return qz::Renderer::pRenderer_;
	qz::Renderer::pRenderer_ = new Renderer;
	return qz::Renderer::pRenderer_;
}

qz::Renderer::Renderer()
{
	auto a = ftxui::ScreenInteractive::Fullscreen();
	this->screen_ = a;
}