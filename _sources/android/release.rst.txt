Release
=======

See also

 - `<https://developer.android.com/build/building-cmdline>`_
 - `<https://developer.android.com/build/building-cmdline#sign_cmdline>`_

.. code-block:: bash

   cd android/SherpaOnnxTtsEngine
   ./gradlew assembleRelease
   ls -lh app/build/outputs/apk/release/*.apk

.. code-block:: bash

  -rw-r--r--@ 1 fangjun  staff   257M Mar 27 15:39 app/build/outputs/apk/release/app-release-unsigned.apk

.. code-block:: bash

   which keytool

.. code-block:: bash

  /Users/fangjun/software/jdk-19.0.1.jdk/Contents/Home/bin/keytool

.. code-block:: bash

   keytool -genkey -v -keystore my-release-key.jks -keyalg RSA -keysize 2048 -validity 10000 -alias my-alias

.. code-block:: bash

   Enter keystore password: <entery the password, see my email>
   Re-enter new password: <enter the password, see my email>
   Enter the distinguished name. Provide a single dot (.) to leave a sub-component empty or press ENTER to use the default value in braces.
   What is your first and last name?
     [Unknown]: k2-fsa
   What is the name of your organizational unit?
     [Unknown]: k2-fsa
   What is the name of your organization?
     [Unknown]: k2-fsa
   What is the name of your City or Locality?
     [Unknown]: Peking
   What is the name of your State or Province?
     [Unknown]: Peking
   What is the two-letter country code for this unit?
     [Unknown]: cn
   Is CN=k2-fsa, OU=k2-fsa, O=k2-fsa, L=Peking, ST=Peking, C=cn correct?
     [no]: yes
   Generating 2,048 bit RSA key pair and self-signed certificate (SHA384withRSA) with a validity of 10,000 days
          for: CN=k2-fsa, OU=k2-fsa, O=k2-fsa, L=Peking, ST=Unknown, C=cn
   [Storing my-release-key.js]

.. code-block:: bash

   ls -lh my-release-key

.. code-block:: bash

  -rw-r--r--  1 fangjun  staff   2.7K Mar 27 16:10 my-release-key

.. code-block:: bash

  file my-release-key

.. code-block:: bash

  my-release-key: data

.. code-block:: bash

   ls -l my-release-key

.. code-block:: bash

  -rw-r--r--  1 fangjun  staff  2732 Mar 27 16:10 my-release-key

.. code-block:: bash

   cd android/SherpaOnnxTtsEngine/app/build/outputs/apk/release
   cp ../../../../../my-release-key ./
   ls -l app-release-unsigned.apk

.. code-block:: bash

  -rw-r--r--@ 1 fangjun  staff  269073239 Mar 27 15:39 app-release-unsigned.apk

.. code-block:: bash

   /Users/fangjun/software/my-android/build-tools/34.0.0/zipalign -v -p 4 ./app-release-unsigned.apk ./app-release-unsigned-aligned.apk

.. code-block:: bash

   ls -l app-release-unsigned-aligned.apk

.. code-block:: bash

  -rw-r--r--@ 1 fangjun  staff  269073239 Mar 27 16:16 app-release-unsigned-aligned.apk

.. code-block:: bash

   /Users/fangjun/software/my-android/build-tools/34.0.0/apksigner sign --ks ./my-release-key --out app-release.apk ./app-release-unsigned-aligned.apk

.. code-block:: bash

   Keystore password for signer #1: <enter the password for the keystore>

.. code-block:: bash

   ls -l ./*.apk

.. code-block:: bash

  -rw-r--r--@ 1 fangjun  staff  269073239 Mar 27 16:16 app-release-unsigned-aligned.apk
  -rw-r--r--@ 1 fangjun  staff  269073239 Mar 27 15:39 app-release-unsigned.apk
  -rw-r--r--@ 1 fangjun  staff  269181994 Mar 27 16:19 app-release.apk

.. code-block:: bash

   which jarsigner

.. code-block:: bash

   /Users/fangjun/software/jdk-19.0.1.jdk/Contents/Home/bin/jarsigner

.. code-block:: bash

   jarsigner --verify -certs -verbose ./app-release.apk > a.txt

To use it with GitHub actions, see `<https://github.com/marketplace/actions/sign-android-release>`_


.. code-block:: bash

   openssl base64 < ./my-release-key.js | tr -d '\n' > ./my-release-key.base64.txt

Set the following secrets:

  - ANDROID_SIGNING_KEY: the content base64.txt
  - ANDROID_SIGNING_KEY_ALIAS: my-alias
  - ANDROID_SIGNING_KEY_STORE_PASSWORD: see my email
