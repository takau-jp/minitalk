#! /bin/bash
> raw_output

SERVER_PID=$1

# $2 以降の引数を実行対象テスト番号として受け取る
TARGET_TESTS=()
if [ $# -ge 2 ]; then
    shift  # $1 は ./client の引数なので除去
    TARGET_TESTS=("$@")
fi


run() {
    TARGETS=("${TARGET_TESTS[@]}")  # 指定されたテストリスト
    TEST_NO="$1"
    TEXT="$2"

    # 特定テストが指定されている場合はフィルタ
    if [ ${#TARGETS[@]} -ne 0 ]; then
        local found=0
        for t in "${TARGETS[@]}"; do
            if [ "$t" = "$TEST_NO" ]; then
                found=1
                break
            fi
        done
        [ $found -eq 0 ] && return
    fi

    ./client "$SERVER_PID" "$(echo -e "【$TEST_NO】  $TEXT")"
    echo -e "【$TEST_NO】$TEXT" >> raw_output
    echo -e "【$TEST_NO】$TEXT"
}

########################################
# A. 正常系（Valid UTF-8）
########################################

# A1 ASCII 'A'
TEXT="\x41"
run "A1" "$TEXT"

# A2 ASCII LF
TEXT="\x0ATEST"
run "A2" "$TEXT"

# A3 BMP あ
TEXT="\xE3\x81\x82"
run "A3" "$TEXT"

# A4 BMP 漢
TEXT="\xE6\xBC\xA2"
run "A4" "$TEXT"

# A5 Emoji 😀
TEXT="\xF0\x9F\x98\x80"
run "A5" "$TEXT"


########################################
# B. UTF-8 境界値
########################################

# B1 ASCII 最大 0x7F
TEXT="\x7F"
run "B1" "$TEXT"

# B2 2バイト最小 U+0080
TEXT="\xC2\x80"
run "B2" "$TEXT"

# B3 2バイト最大 U+07FF
TEXT="\xDF\xBF"
run "B3" "$TEXT"

# B4 3バイト最小 U+0800
TEXT="\xE0\xA0\x80"
run "B4" "$TEXT"

# B5 3バイト最大 U+FFFF
TEXT="\xEF\xBF\xBF"
run "B5" "$TEXT"

# B6 4バイト最小 U+10000
TEXT="\xF0\x90\x80\x80"
run "B6" "$TEXT"

# B7 4バイト最大 U+10FFFF
TEXT="\xF4\x8F\xBF\xBF"
run "B7" "$TEXT"


########################################
# C. 非文字（Non-characters）
########################################

# C1 U+FDD0
TEXT="\xEF\xB7\x90"
run "C1" "$TEXT"

# C2 U+FDEF
TEXT="\xEF\xB7\xAF"
run "C2" "$TEXT"

# C3 U+FFFE
TEXT="\xEF\xBF\xBE"
run "C3" "$TEXT"

# C4 U+FFFF
TEXT="\xEF\xBF\xBF"
run "C4" "$TEXT"

# C5 U+1FFFE
TEXT="\xF0\x9F\xBF\xBE"
run "C5" "$TEXT"

# C6 U+10FFFF (非文字扱い)
TEXT="\xF4\x8F\xBF\xBF"
run "C6" "$TEXT"


########################################
# D. 制御文字 / 区切り文字
########################################

# D1 TAB
TEXT="\x09"
run "D1" "$TEXT"

# D2 LF
TEXT="\x0ATEST"
run "D2" "$TEXT"

# D3 CR
TEXT="\x0D"
run "D3" "$TEXT"

# D4 ESC
TEXT="\x1B"
run "D4" "$TEXT"


########################################
# E. 不正 UTF-8（Invalid sequences）
########################################

# E1 単独継続バイト
TEXT="\x80"
run "E1" "$TEXT"

# E2 不正先頭 C0
TEXT="\xC0"
run "E2" "$TEXT"

# E3 上位サロゲート U+D800
TEXT="\xED\xA0\x80"
run "E3" "$TEXT"

# E4 下位サロゲート U+DC00
TEXT="\xED\xB0\x80"
run "E4" "$TEXT"

# E5 範囲外 > U+10FFFF
TEXT="\xF5\x80\x80\x80"
run "E5" "$TEXT"


########################################
# F. 非最短形式（Overlong）
########################################

# F1 '/' 非最短
TEXT="\xC0\xAF"
run "F1" "$TEXT"

# F2 'A' 非最短
TEXT="\xC1\x81"
run "F2" "$TEXT"

# F3 NULL 非最短
TEXT="\xC0\x80"
run "F3" "$TEXT"

# F4 3バイト非最短
TEXT="\xE0\x81\x81"
run "F4" "$TEXT"

# F5 4バイト非最短
TEXT="\xF0\x80\x81\x81"
run "F5" "$TEXT"


########################################
# G. 途切れた / 部分的 UTF-8
########################################

# G1 2バイト途切れ
TEXT="\xC2"
run "G1" "$TEXT"

# G2 3バイト途切れ
TEXT="\xE2"
run "G2" "$TEXT"

# G3 3バイト途中まで
TEXT="\xE2\x82"
run "G3" "$TEXT"

# G4 4バイト途切れ
TEXT="\xF0"
run "G4" "$TEXT"

# G5 4バイト途中まで
TEXT="\xF0\x9F"
run "G5" "$TEXT"


########################################
# H. ゼロ幅・不可視文字
########################################

# H1 全角スペース
TEXT="\xE3\x80\x80"
run "H1" "$TEXT"

# H2 Zero-width space (ZWSP)
TEXT="\xE2\x80\x8B"
run "H2" "$TEXT"

# H3 BOM FEFF
TEXT="\xEF\xBB\xBF"
run "H3" "$TEXT"

# H4 RLO (右から左)
TEXT="\xE2\x80\xAE"
run "H4" "$TEXT"


########################################
# I. 歴史的 UTF-8 拡張（不正）
########################################

# I1 5バイト（不正）
TEXT="\xF8\x88\x80\x80\x80"
run "I1" "$TEXT"

# I2 6バイト（不正）
TEXT="\xFC\x84\x80\x80\x80\x80"
run "I2" "$TEXT"


########################################
# J. 継続バイト異常
########################################

# J1 継続3連
TEXT="\x80\x80\x80"
run "J1" "$TEXT"

# J2 継続バイト混在
TEXT="\x80\xBF\x80"
run "J2" "$TEXT"
