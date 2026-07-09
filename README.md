##
A tree sitter parser for haxe.

I've only tested this using nvim-treesitter.

If you are getting an error on loading parser after 0.11.x, check the config below and ensure you are including `src/scanner.c` in the file list for the config (only relevant for the legacy `master`-branch setup — the newer `main` branch compiles every C source in `src/` automatically).

## Use

nvim-treesitter was rewritten and the config differs quite a bit between the
current (`main` branch) version and the legacy (`master` branch) version. Pick
the section that matches the version you have installed.

### Newest nvim-treesitter (`main` branch)

The `main` rewrite dropped `ensure_installed`/`configs.setup` and instead:

- registers custom parsers inside a `User TSUpdate` autocommand,
- installs queries straight from the parser repo (no manual `cp` needed),
- compiles every C source in `src/` automatically (so no `files` list, and the
  0.11.x scanner load error doesn't apply here),
- enables highlighting with the native `vim.treesitter.start()`.

Add this to your `init.lua` (or anywhere loaded at startup):

```lua
-- Register the Haxe parser. The main branch reads this when it
-- installs/updates parsers, so register it in a `TSUpdate` autocommand.
vim.api.nvim_create_autocmd("User", {
  pattern = "TSUpdate",
  callback = function()
    require("nvim-treesitter.parsers").haxe = {
      install_info = {
        url = "https://github.com/vantreeseba/tree-sitter-haxe",
        branch = "main",
        -- pull the highlights/locals/injections/folds queries from the repo
        queries = "queries",
      },
    }
  end,
})

-- Associate *.hx files with the `haxe` filetype/language.
vim.filetype.add({ extension = { hx = "haxe" } })

-- Enable tree-sitter highlighting for Haxe buffers.
vim.api.nvim_create_autocmd("FileType", {
  pattern = "haxe",
  callback = function()
    vim.treesitter.start()
  end,
})
```

Then install the parser with:

```
:TSInstall haxe
```

and update it later with `:TSUpdate haxe`. Because the `queries` field points at
this repo's `queries/` folder, the highlight queries are installed for you.

### Legacy nvim-treesitter (`master` branch)

Install nvim-treesitter.  
Clone this repo, and run tree-sitter generate (you may have to install globally).  
Once generated, copy the queries to the nvim-treesitter folder

```sh
cp queries/* ~/.vim/BUNDLERPATH/nvim-treesitter/queries/haxe
```

For example if you're using lazy.nvim run:

```
cp queries/* ~/.local/share/nvim/lazy/nvim-treesitter/queries/haxe
```

You may have to create the haxe folder.

Add these snippets to your treesitter config or anywhere in your `init.lua`:

This enables and ensures the parser is installed, and that highlight is enabled.
```
local configs = require "nvim-treesitter.configs"
configs.setup {
  ensure_installed = { "haxe" }, -- Install the Haxe parser
  highlight = {
    enable = true,              -- false will disable the whole extension
    additional_vim_regex_highlighting = false,
  },
}
```

```
local parser_config = require "nvim-treesitter.parsers".get_parser_configs()
parser_config.haxe = {
  install_info = {
    url = "https://github.com/vantreeseba/tree-sitter-haxe",
    files = {"src/parser.c", "src/scanner.c"},
    -- optional entries:
    branch = "main",
  },
  filetype = "haxe",
}
```

Open nvim, and run TSInstallFromGrammer haxe

This should get you running.

### I still don't get highlighting...

You might have to add the haxe filetype for neovim to be able to associate the grammar to your files.
To do this create the appropriate file with:

```
touch ~/.nvim/filetype.lua
```

And add the following content:

```
vim.filetype.add({
  extension = {
    hx = 'haxe',
  },
})
```

### What it looks like / does so far (the color scheme is of course customizeable through the highlights / etc in vim).

![image](https://user-images.githubusercontent.com/316782/117491153-72423080-af35-11eb-95ca-ebe9847ecd4b.png)
