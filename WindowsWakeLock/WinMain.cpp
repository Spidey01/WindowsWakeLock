
#include <Windows.h>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
#if 0
	// Set new state to prevent system sleep (note: still allows screen saver)
	m_previousExecutionState = NativeMethods.SetThreadExecutionState(
		NativeMethods.ES_CONTINUOUS | NativeMethods.ES_SYSTEM_REQUIRED);
	if (0 == m_previousExecutionState)
	{
		MessageBox.Show("Call to SetThreadExecutionState failed unexpectedly.",
			Title, MessageBoxButton.OK, MessageBoxImage.Error);
		// No way to recover; fail gracefully
		Close();
	}
#endif
	LPCTSTR title = _T("Windows Wake Lock");
	EXECUTION_STATE previous;
	previous = SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED);
	if (previous) {
		MessageBox(NULL, _T("System will NOT sleep until OK is pressed."), title, MB_OK | MB_ICONEXCLAMATION);
	}
	else {
		MessageBox(NULL, _T("Failed SetThreadExecutionState()"), title, MB_OK | MB_ICONERROR);
	}
	SetThreadExecutionState(previous);
	return 0;
}