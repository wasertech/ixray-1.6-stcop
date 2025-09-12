# Preferred Fallback Language Feature

## Overview

This feature adds support for fallback language translation to address XML parsing errors when using languages other than English or Russian.

## Configuration

Add the following section to your `gamedata/configs/engine_external.ltx`:

```ltx
[localization]
PreferedFallbackLanguage = eng
```

## How It Works

1. When a string translation is requested, the system first looks in the current language's XML files
2. If the string is not found, it falls back to the preferred fallback language
3. If still not found, it returns the original string ID

## Example Scenario

**Setup:**
- Current language: French (`fra`)
- Fallback language: English (`eng`)

**String Table Contents:**
- French has: `st_hello = "Bonjour"`
- French missing: `st_goodbye`
- English has: `st_goodbye = "Goodbye"`

**Translation Results:**
- `translate("st_hello")` → `"Bonjour"` (from French)
- `translate("st_goodbye")` → `"Goodbye"` (from English fallback)
- `translate("st_missing")` → `"st_missing"` (not found in either)

## Testing

To test this functionality:

1. Set your language to French in `gamedata/configs/localization.ltx`:
   ```ltx
   [string_table]
   language = fra
   ```

2. Ensure `PreferedFallbackLanguage = eng` is set in `engine_external.ltx`

3. Create incomplete French translation files in `gamedata/configs/text/fra/`

4. Ensure complete English translation files exist in `gamedata/configs/text/eng/`

5. Run the game - missing French strings should display in English instead of causing XML errors

## Implementation Details

- **Files Modified:**
  - `src/xrEngine/EngineExternal.h` - Added `GetPreferredFallbackLanguage()` method
  - `src/xrEngine/EngineExternal.cpp` - Implemented fallback language getter
  - `src/xrEngine/string_table.h` - Extended data structure for fallback support
  - `src/xrEngine/string_table.cpp` - Added fallback loading and translation logic
  - `gamedata/configs/engine_external.ltx` - Added default configuration

- **Minimal Changes:** Only 91 lines added across 5 files, focusing specifically on the fallback functionality