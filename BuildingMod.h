#ifndef BUILDINGMOD_H
#define BUILDINGMOD_H
#include "cwmods/cwmods.h"
#include "DButton.h"
#include "BuildWindow.h"

class BuildingMod : GenericMod {
private:
	DButton buildButton = DButton(DIK_GRAVE);
	SYSTEMTIME lastPlacementTime;
	SYSTEMTIME lastBreakTime;
	SYSTEMTIME lastPickTime;
	bool buildMode = false;
	cube::Game* game;
	f32 reachRange = 40.0;
	cube::Block currentBlock;
	BuildWindow* buildWindow;

public:
	bool InBuildMode();
	void ToggleBuildMode();
	cube::Block GetCurrentBlock();
	void SelectBlock(cube::Block block, bool verbose = true);
	void SetBlockColor(cube::Block block, bool verbose = true);

private:
	void PrintMessagePrefix();
	bool ReadyToBreak();
	void BreakAction();
	bool ReadyToPlace();
	void PlaceAction();
	bool ReadyToPick();
	void PickAction();
	bool InOtherGUI();

	// Event handlers
	virtual void Initialize() override;
	virtual void OnGameTick(cube::Game* game) override;
	virtual void OnGetKeyboardState(BYTE* diKeys) override;
	virtual void OnGetMouseState(DIMOUSESTATE* diMouse) override;
	virtual void OnPresent(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags) override;
	virtual int OnWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};

#endif
