Setup
=====

1. Install the dependencies in ``./docs/requirements.txt``.

.. literalinclude:: ../../requirements.txt

2. Use ``sphinx-quickstart`` to generate the skeleton. When it prompts:

.. code-block::

    Separate source and build directories(y/n)

Answer yes.

3. Edit ``docs/source/conf.py`` and add the following lines to it:

.. code-block:: python

    import sphinx_rtd_theme
    extensions = [
        'sphinx.ext.autodoc',
        'sphinx.ext.autosummary',
        'sphinx.ext.githubpages',
        'sphinx.ext.mathjax',
        'sphinx.ext.napoleon',
        'sphinx.ext.todo',
        'sphinx.ext.viewcode',
        'sphinxcontrib.bibtex',
    ]

    html_theme = 'sphinx_rtd_theme'

    master_doc = 'index'
    pygments_style = 'sphinx'
    html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]
    smartquotes = False
    html_show_sourcelink = True

    html_context = {
        'display_github': True,
        'github_user': 'csu-fangjun',
        'github_repo': 'notes',
        'github_version': 'master',
        'conf_py_path': '/docs/source/',
    }

    html_theme_options = {
        'logo_only': False,
        'display_version': True,
        'prev_next_buttons_location': 'bottom',
        'style_external_links': True,
    }
    latex_engine = 'xelatex'

4. To generate the notes in pdf format, use ``make latex``,
   which generates lots of ``tex`` files in ``./build/latex``.
   Switch to ``build/latex`` and run ``make``. Assume that
   you have installed the software to compile ``tex`` files.
   If will generate ``notes.pdf``.
