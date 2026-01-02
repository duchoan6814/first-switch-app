#ifndef STYLE_H
#define STYLE_H

// --- Điều khiển con trỏ ---
#define CLR_SCR "\x1b[2J"
#define RESET "\x1b[0m"
#define HOME "\x1b[1;1H"
#define BOLD "\x1b[1m"
#define MOVE(row, col) "\x1b[" #row ";" #col "H"

// --- Bộ màu (Themes) ---

// Theme 1: Nintendo Classic (Đỏ - Trắng)
#define NINTENDO_BG "\x1b[41m" // Nền đỏ
#define NINTENDO_FG "\x1b[37m" // Chữ trắng

// Theme 2: Hacker / Matrix (Đen - Xanh lá)
#define HACKER_BG "\x1b[40m" // Nền đen
#define HACKER_FG "\x1b[32m" // Chữ xanh lá

// Theme 3: Ocean Blue (Xanh dương - Trắng)
#define OCEAN_BG "\x1b[44m" // Nền xanh dương
#define OCEAN_FG "\x1b[97m" // Chữ trắng sáng

// Theme 4: Dark Mode (Xám đậm - Vàng)
#define DARK_BG "\x1b[100m" // Nền xám
#define DARK_FG "\x1b[93m"  // Chữ vàng sáng

// Cấu hình UI mặc định (Bạn chỉ cần đổi ở đây để đổi cả App)
#define SELECTED_STYLE OCEAN_BG OCEAN_FG BOLD
#define UNSELECTED_STYLE RESET

#endif