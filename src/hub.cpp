#include <ftxui/component/screen_interactive.hpp>

#include "hub.hpp"

qz::Hub::Hub(std::string _listName)
{
	this->list_ = qz::list::get(_listName);

	std::function<void()> placeholder = [] {};

	this->bWrite_		= ftxui::Button("Write", placeholder)		;
	this->bCard_		= ftxui::Button("Card", placeholder)		;
	this->bTrueFalse_	= ftxui::Button("True False", placeholder)	;
	this->bChoose_		= ftxui::Button("Choose", placeholder)		;
	this->bAdd_			= ftxui::Button("Add", placeholder)			;
	this->bEdit_		= ftxui::Button("Edit", placeholder)		;
	this->bDelete_		= ftxui::Button("Delete", placeholder)		;
	this->bHome_		= ftxui::Button("Home", placeholder)		;
	this->bQuit_		= ftxui::Button("Quit", placeholder)		;

	this->mTheme_		= ftxui::Menu(&this->vStrTheme_, &this->menuIndex_);
	this->mVersion_		= ftxui::Menu(&this->vStrVersion_, &this->menuIndex_);

	this->container_ = ftxui::Container::Vertical(
	{
		this->bWrite_,
		this->bCard_,
		this->bTrueFalse_,
		this->bChoose_,
		this->bAdd_,
		this->bEdit_,
		this->bDelete_,
		this->bHome_,
		this->bQuit_,

		this->mTheme_,
		this->mVersion_,
	});

	std::function<ftxui::Element()> renderer = [&]
	{
		int x = ftxui::ScreenInteractive::Active()->dimx();
		int space = x - 2 * std::floor(x / 2);

		this->vStrTheme_.clear();
		this->vStrVersion_.clear();

		for (qz::pair pair : this->list_.vP)
		{
			this->vStrTheme_.push_back(pair.theme);
			this->vStrVersion_.push_back(pair.version);
		}

		return ftxui::hbox(
		{
			ftxui::vbox(
			{
				ftxui::frame(ftxui::vscroll_indicator(ftxui::hbox(
				{
					this->mTheme_->Render() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, x / 5),
					this->mVersion_->Render() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, x / 5),
					ftxui::filler(),
				}))) | ftxui::center | ftxui::border
			}) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, x / 2),

			ftxui::filler() | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, space),

			ftxui::vbox(
			{
				ftxui::vbox(
				{
					ftxui::hbox({this->bWrite_->Render(), this->bCard_->Render(),}) | ftxui::xflex,
					ftxui::hbox({this->bTrueFalse_->Render(), this->bChoose_->Render(),}) | ftxui::xflex,
				}) | ftxui::border,
				this->bAdd_->Render(),
				this->bEdit_->Render(),
				this->bDelete_->Render(),
				ftxui::hbox({this->bHome_->Render(), this->bQuit_->Render(),}) | ftxui::border,
			}
			) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, x / 2) | ftxui::border
		});
	};

	this->Renderer = ftxui::Renderer(this->container_, renderer);
}