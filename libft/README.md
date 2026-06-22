# libft

42Tokyo カリキュラム向けに実装した C 言語ユーティリティライブラリです。
libft・get_next_line・ft_printf の 3 モジュールをひとつのアーカイブ `libft.a` にまとめています。

---

## ビルド

```sh
make        # libft.a を生成
make san    # AddressSanitizer + UBSanitizer 付きでビルド
make debug  # デバッグシンボル付きでビルド
make clean  # オブジェクトファイルを削除
make fclean # libft.a とオブジェクトファイルを削除
make re     # fclean してから再ビルド
```

インクルードパスに `include/` を追加し、`libft.h` をインクルードするだけで全機能を使えます。

```c
#include "libft.h"
```

---

## libft

標準 C ライブラリの主要関数を再実装したモジュールです。

### 文字分類 (`ft_ctype`)

| 関数 | 説明 |
|------|------|
| `ft_isalnum(c)` | 英数字かどうかを判定 |
| `ft_isalpha(c)` | 英字かどうかを判定 |
| `ft_isascii(c)` | ASCII 文字かどうかを判定 |
| `ft_isblank(c)` | スペースまたはタブかどうかを判定 |
| `ft_iscntrl(c)` | 制御文字かどうかを判定 |
| `ft_isdigit(c)` | 数字かどうかを判定 |
| `ft_isgraph(c)` | 印字可能な非空白文字かどうかを判定 |
| `ft_islower(c)` | 小文字かどうかを判定 |
| `ft_isprint(c)` | 印字可能文字かどうかを判定 |
| `ft_ispunct(c)` | 句読点・記号かどうかを判定 |
| `ft_isspace(c)` | 空白文字かどうかを判定 |
| `ft_isupper(c)` | 大文字かどうかを判定 |
| `ft_isxdigit(c)` | 16 進数字かどうかを判定 |
| `ft_tolower(c)` | 大文字を小文字に変換 |
| `ft_toupper(c)` | 小文字を大文字に変換 |

### 文字列・メモリ操作 (`ft_string`)

| 関数 | 説明 |
|------|------|
| `ft_bzero(s, n)` | メモリ領域をゼロ埋め |
| `ft_memchr(s, c, n)` | メモリから文字を検索 |
| `ft_memcmp(s1, s2, n)` | メモリ領域を比較 |
| `ft_memcpy(dst, src, n)` | メモリをコピー（重複不可） |
| `ft_memmove(dst, src, n)` | メモリをコピー（重複対応） |
| `ft_memset(s, c, n)` | メモリ領域を指定バイトで埋める |
| `ft_split(s, c)` | 区切り文字で文字列を分割し配列を返す |
| `ft_split_set(s, char_set)` | 区切り文字セットで文字列を分割 |
| `ft_strcat(dest, src)` | 文字列を末尾に連結 |
| `ft_strchr(s, c)` | 文字列から文字を検索（前方） |
| `ft_strcmp(s1, s2)` | 文字列を比較 |
| `ft_strcpy(dest, src)` | 文字列をコピー |
| `ft_strdup(s)` | 文字列を複製（malloc） |
| `ft_striteri(s, f)` | 各文字にインデックス付きで関数を適用（破壊的） |
| `ft_strjoin(s1, s2)` | 2 つの文字列を結合して新しい文字列を返す |
| `ft_strlcat(dst, src, size)` | バッファサイズを考慮して文字列を連結 |
| `ft_strlcpy(dst, src, size)` | バッファサイズを考慮して文字列をコピー |
| `ft_strlen(s)` | 文字列の長さを返す |
| `ft_strmapi(s, f)` | 各文字にインデックス付きで関数を適用し新しい文字列を返す |
| `ft_strncat(dest, src, n)` | 最大 n 文字を末尾に連結 |
| `ft_strncmp(s1, s2, n)` | 最大 n 文字まで文字列を比較 |
| `ft_strncpy(dst, src, n)` | 最大 n 文字コピー |
| `ft_strndup(s, n)` | 最大 n 文字の複製を返す |
| `ft_strnlen(s, maxlen)` | 最大 maxlen までの文字列長を返す |
| `ft_strnstr(big, little, len)` | len 文字以内で部分文字列を検索 |
| `ft_strrchr(s, c)` | 文字列から文字を検索（後方） |
| `ft_strtrim(s1, set)` | 文字列の両端から指定文字セットを除去 |
| `ft_substr(s, start, len)` | 部分文字列を切り出して返す |

### 変換・メモリ確保 (`ft_stdlib`)

| 関数 | 説明 |
|------|------|
| `ft_abs_uint(n)` | int の絶対値を unsigned int で返す |
| `ft_abs_ulong(n)` | long の絶対値を unsigned long で返す |
| `ft_atoi(nptr)` | 文字列を int に変換 |
| `ft_atof(str)` | 文字列を double に変換 |
| `ft_calloc(nmemb, size)` | ゼロ初期化したメモリを確保 |
| `ft_itoa(n)` | int を文字列に変換（malloc） |
| `ft_realloc(ptr, old_size, new_size)` | メモリを再確保（失敗時は元 ptr を free しない） |
| `ft_reallocf(ptr, old_size, new_size)` | メモリを再確保（失敗時は元 ptr も free する） |

### 出力 (`ft_stdio`)

| 関数 | 説明 |
|------|------|
| `ft_putchar_fd(c, fd)` | 1 文字をファイルディスクリプタに出力 |
| `ft_putstr_fd(s, fd)` | 文字列をファイルディスクリプタに出力 |
| `ft_putendl_fd(s, fd)` | 文字列と改行をファイルディスクリプタに出力 |
| `ft_putnbr_fd(n, fd)` | 整数をファイルディスクリプタに出力 |
| `ft_putchar_fd_bytes(c, fd)` | 出力したバイト数を返す版 |
| `ft_putstr_fd_bytes(s, fd)` | 出力したバイト数を返す版 |
| `ft_putendl_fd_bytes(s, fd)` | 出力したバイト数を返す版 |
| `ft_putnbr_fd_bytes(n, fd)` | 出力したバイト数を返す版 |

### 連結リスト (`ft_lst`)

`t_list` 構造体を使った単方向リストです。

```c
typedef struct s_list
{
    void         *content;
    struct s_list *next;
} t_list;
```

| 関数 | 説明 |
|------|------|
| `ft_lstnew(content)` | 新しいノードを作成 |
| `ft_lstadd_front(lst, new)` | リスト先頭にノードを追加 |
| `ft_lstadd_back(lst, new)` | リスト末尾にノードを追加 |
| `ft_lst_push_front(lst, content)` | content からノードを作成して先頭に追加（bool を返す） |
| `ft_lst_push_back(lst, content)` | content からノードを作成して末尾に追加（bool を返す） |
| `ft_lst_pop_front(lst)` | 先頭ノードを取り出して content を返す |
| `ft_lst_pop_back(lst)` | 末尾ノードを取り出して content を返す |
| `ft_lstsize(lst)` | リストのノード数を返す |
| `ft_lstlast(lst)` | 最後のノードを返す |
| `ft_lstdelone(lst, del)` | ノード 1 つを解放 |
| `ft_lstclear(lst, del)` | リスト全体を解放 |
| `ft_lstiter(lst, f)` | 全ノードに関数を適用 |
| `ft_lstmap(lst, f, del)` | 全ノードに関数を適用した新リストを返す |

### 数学 (`ft_math`)

| 関数 | 説明 |
|------|------|
| `ft_fabs(x)` | double の絶対値 |
| `ft_round(x)` | 四捨五入 |
| `ft_sqrt(x)` | 平方根 |
| `ft_rand_r(seed)` | 再入可能な疑似乱数生成 |
| `ft_xorshift(seed)` | XOR シフトによる高速疑似乱数生成 |

---

## get_next_line

ファイルディスクリプタから 1 行ずつ読み込む関数です。

```c
char *get_next_line(int fd);
```

- 戻り値: 読み込んだ行（改行文字含む）。EOF に達した場合は末尾の不完全な行を返し、それ以降は `NULL` を返す。
- 呼び出し側が戻り値を `free` する責任を持つ。
- エラー時は `NULL` を返す。

### 内部構造

| 構造体 | フィールド | 説明 |
|--------|-----------|------|
| `t_buf` | `data[BUFFER_SIZE]` | read バッファ |
| | `read_bytes` | 最後の read で取得したバイト数 |
| | `used_bytes` | バッファのうち既に消費したバイト数 |
| `t_line` | `data` | 行データ（動的確保） |
| | `len` | 現在の行の長さ |
| | `allocated_size` | 確保済みサイズ |

### コンパイル時オプション

| マクロ | デフォルト | 説明 |
|--------|-----------|------|
| `BUFFER_SIZE` | 16384 | read バッファサイズ（コンパイル時に上書き可能） |

```sh
gcc -D BUFFER_SIZE=4096 ...
```

---

## ft_printf

`printf` 系関数の独自実装です。

```c
int ft_printf(const char *format, ...);
int ft_dprintf(int fd, const char *format, ...);
int ft_sprintf(char *str, const char *format, ...);
int ft_snprintf(char *str, size_t size, const char *format, ...);
```

- 戻り値: 出力したバイト数。エラー時は `-1`。
- `ft_snprintf` は `size - 1` 文字まで書き込み、末尾を `'\0'` で終端する。

### サポートする変換指定子

| 指定子 | 説明 |
|--------|------|
| `%c` | char 1 文字 |
| `%lc` | ワイド文字（`wchar_t`）、UTF-8 に変換して出力 |
| `%s` | 文字列 |
| `%ls` | ワイド文字列（`wchar_t *`）、UTF-8 に変換して出力 |
| `%d`, `%i` | 符号付き 10 進整数 |
| `%u` | 符号なし 10 進整数 |
| `%o` | 符号なし 8 進整数 |
| `%x`, `%X` | 符号なし 16 進整数（小文字 / 大文字） |
| `%p` | ポインタアドレス |
| `%f`, `%F` | 浮動小数点数（固定小数点形式） |
| `%e`, `%E` | 浮動小数点数（指数形式） |
| `%g`, `%G` | `%e` / `%f` のうち短い方を自動選択 |
| `%a`, `%A` | 浮動小数点数（16 進指数形式） |
| `%n` | これまでに出力したバイト数を引数に書き込む |
| `%%` | `%` リテラル |

### フラグ

| フラグ | 説明 |
|--------|------|
| `-` | 左揃え |
| `+` | 正数にも符号を付ける |
| ` ` (スペース) | 正数の符号位置にスペースを出力 |
| `#` | 代替形式（`%o` → `0` 接頭辞、`%x` → `0x`、`%a/%e/%f/%g` → 小数点を強制） |
| `0` | 空白の代わりにゼロで埋める |

### 長さ修飾子

| 修飾子 | 説明 |
|--------|------|
| `h` | `short` |
| `hh` | `char` |
| `l` | `long` / `wchar_t` |
| `ll` | `long long` |
| `j` | `intmax_t` |
| `z` | `size_t` |
| `t` | `ptrdiff_t` |
| `L` | `long double`（binary80）|

### 浮動小数点の実装

IEEE 754 に準拠した正確な変換を実装しています。

- **binary64**（`double`）: 指数部 11 ビット、仮数部 52 ビット
- **binary80**（`long double` on x86/Apple Silicon）: 指数部 15 ビット、仮数部 63 ビット
- NaN・Inf・非正規化数（subnormal）・ゼロを正しく処理
- Banker's rounding（最近接偶数丸め）を実装

### プラットフォーム対応

macOS（`__APPLE__`）と Linux で一部挙動が異なります（UTF-8 最大バイト長、`PRINTF_RESULT_LIMIT` など）。
各ファイルの `_darwin` サフィックス版がmacOS向けの実装です。

---

## ディレクトリ構成

```
libft/
├── include/                  # 公開ヘッダ
│   ├── libft.h
│   ├── ft_ctype.h
│   ├── ft_stdio.h
│   ├── ft_stdlib.h
│   ├── ft_string.h
│   ├── ft_lst.h
│   └── ft_math.h
├── ft_printf/
├── ctype/
├── stdio/
├── stdlib/
├── string/
├── lst/
├── math/
├── get_next_line/
└── Makefile
```

---

## ライセンス

42Tokyo の課題として作成したコードです。
