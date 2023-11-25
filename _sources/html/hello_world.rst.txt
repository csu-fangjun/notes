Hello world
===========

.. literalinclude:: ./code/hello_world.html
   :language: html
   :caption: hello_world.html

comments
--------

.. code-block:: html

   <!-- this is a comment -->

images
------

.. code-block:: html

   <img src="a.png" alt="yyy"></img>
   <img src="foo/bar/b.png" alt="yyy"></img>
   <img src="../../c.png" alt="yyy"></img>

ordered lists
-------------

.. code-block:: html

   <p> The following points </p>

   <ol>
     <li> First </li>
     <li> Second </li>
   </ol>

unordered lists
---------------

.. code-block:: html

   <p> The following points </p>

   <ul>
     <li> foo </li>
     <li> bar </li>
   </ul>

links
-----

.. code-block:: html

   <a href="https://www.google.com">some text</a>

div
---

.. code-block:: html

  <label for="quota">Number of primes:</label>
  <input type="text" id="quota" name="quota" value="1000000" />

  <button id="generate">Generate primes</button>
  <button id="reload">Reload</button>

  <div id="output"></div>

  <pre readonly class="event-log"></pre>



  // js
  const quota = document.querySelector("#quota");
  const output = document.querySelector("#output");
  document.querySelector("#generate").addEventListener("click", () => {
    const primes = generatePrimes(quota.value);


    // note we use output.textContent
    output.textContent = `Finished generating ${quota.value} primes!`;
  });

  document.querySelector("#reload").addEventListener("click", () => {
    document.location.reload();
  });

  const log = document.querySelector(".event-log");
  log.textContent = "";



