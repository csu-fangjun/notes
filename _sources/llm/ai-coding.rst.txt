ai-coding
=========

.. code-block::

   npm install -g @anthropic-ai/claude-code

After installation, run::

  claude

If it throws::

  Unable to connect to Anthropic services

  Failed to connect to api.anthropic.com: ECONNREFUSED

  Please check your internet connection and network settings.

  Note: Claude Code might not be available in your country. Check supported
  countries at https://anthropic.com/supported-countries

Edit ``~/.claude.json`` and add a line to the end of the file::

  "hasCompletedOnboarding": true

Then change ``~/.claude/settings.json`` to setup the keys.

After that, run::

  claude

  alias claude='claude --dangerously-skip-permissions'
