#pragma once

#include "Player.h"
#include "PlayerOptions.h"


class Option {
protected:
	PlayerOptions m_chosenOption;
	std::string m_outputText;
	std::string m_optionText;

public:
	Option(PlayerOptions chosenOption, const std::string& outputText) : m_chosenOption(chosenOption), m_outputText(outputText) { }

	void SetOptionText(const std::string& optionText);

	const std::string& GetOutputText() const;
	PlayerOptions GetChosenOption() const;

	virtual bool Evaluate(const std::string& optionText, Player& player) = 0;
};

class MoveOption : public Option {
private:
	Room::JoiningDirections m_directionToMove;

public:
	MoveOption(Room::JoiningDirections joiningDirection, PlayerOptions chosenOption, const std::string& outputText) : 
		Option(chosenOption, outputText), m_directionToMove(joiningDirection) { }

	virtual bool Evaluate(const std::string& optionText, Player& player);
};

class QuitOption : public Option {
private:
	bool m_shouldQuit;

public:
	QuitOption(const std::string& outputText) : Option(PlayerOptions::Quit, outputText), m_shouldQuit(false) { }

	bool ShouldQuit() const { return m_shouldQuit; };
	virtual bool Evaluate(const std::string& optionText, Player& player);
};