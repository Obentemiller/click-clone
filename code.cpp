#include <windows.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <chrono>

#define RESET "\033[0m"
#define GREEN "\033[32m"  

// Estrutura para armazenar os eventos do mouse
struct MouseEvent {
    POINT position;
    bool leftClick;
    bool rightClick;
    DWORD time;  // Tempo em milissegundos do evento
};

bool wasLeftClick = false;
bool wasRightClick = false;

// Função para verificar debouncing de cliques
bool isClick(bool currentState, bool &wasClicked) {
    if (currentState && !wasClicked) {
        wasClicked = true;
        return true;
    }
    if (!currentState) {
        wasClicked = false;
    }
    return false;
}

void click_clone(int precision) {
    std::vector<MouseEvent> mouseEvents;
    POINT cursorPos;
    bool recording = true;
    DWORD startTime = GetTickCount();  // Obtém o tempo inicial

    std::cout << "Gravando movimentos do mouse. Pressione ESC para parar e ENTER para reproduzir." << std::endl;

    // Captura os movimentos e cliques do mouse até ESC ser pressionado
    while (recording) {
        // Captura a posição atual do cursor do mouse
        if (GetCursorPos(&cursorPos)) {
            // Verifica se houve um clique (com debouncing)
            bool leftClick = isClick(GetAsyncKeyState(VK_LBUTTON), wasLeftClick);
            bool rightClick = isClick(GetAsyncKeyState(VK_RBUTTON), wasRightClick);

            // Armazena o evento do mouse no vetor
            MouseEvent event;
            event.position = cursorPos;
            event.leftClick = leftClick;
            event.rightClick = rightClick;
            event.time = GetTickCount() - startTime;  // Tempo relativo desde o início

            mouseEvents.push_back(event);
        }

        // Verifica se a tecla ESC foi pressionada para parar a gravação
        if (GetAsyncKeyState(VK_ESCAPE)) {
            std::cout << "Gravação interrompida." << std::endl;
            recording = false;
        }

        // Pequeno delay para não sobrecarregar a CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(precision));
    }

    std::cout << "Gravação finalizada. Pressione ENTER para reproduzir os movimentos." << std::endl;

    // Aguarda até que o usuário pressione ENTER para reproduzir
    while (true) {
        if (GetAsyncKeyState(VK_RETURN)) {
            break;
        }
    }

    std::cout << "Reproduzindo movimentos do mouse..." << std::endl;

    // Reproduz os movimentos gravados
    DWORD replayStartTime = GetTickCount();  // Tempo de início da reprodução
    for (const auto& event : mouseEvents) {
        // Aguarda o tempo correto baseado na diferença de tempo dos eventos
        DWORD currentTime = GetTickCount();
        DWORD waitTime = event.time - (currentTime - replayStartTime);
        if (waitTime > 0) {
            Sleep(waitTime);
        }

        // Move o cursor do mouse para a posição gravada
        SetCursorPos(event.position.x, event.position.y);

        // Simula os cliques gravados
        if (event.leftClick) {
            // Simula um clique esquerdo
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (event.rightClick) {
            // Simula um clique direito
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        }
    }

    std::cout << "Reprodução concluída." << std::endl;
}

std::string logo = R"(
  _  ___  __    _ _      _          _                  
 | |/ / |/ /   | (_)    | |        | |                 
 | ' /| ' / ___| |_  ___| | __  ___| | ___  _ __   ___ 
 |  ; |  ; / __| | |/ __| |/ / / __| |/ _ \| '_ \ / _ \
 | . \| . \ (__| | | (__|   ; | (__| | (_) | | | |  __/
 |_|\_\_|\_\___|_|_|\___|_|\_\ \___|_|\___/|_| |_|\___|
    @github Obentemiller                                          
        
)";


int main() {
    char q = ' ';
    int precision = 20;
    std::cout << GREEN << logo << " pressione 'q' para começar a gravar..." << std::endl;

    std::cout << " valor de precisão (considere o mínimo de precisão 50, e o máximo 20): ";
    std::cin >> precision;

    q = _getch();

    if (q == 'q') {
        click_clone(precision);
    }
    return 0;
}
