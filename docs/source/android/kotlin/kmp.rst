Kotlin Multiplatform
====================

project_root/build.gradle.kts contains ``compose.desktop``, which contains::

  compose.desktop {
    application {
      mainClass = "MainKt"  
      nativeDistributions {
        targetFormats(TargetFormat.Dmg, TargetFormat.Msi, TargetFormat.Deb)
        packageName = "demo"
        packageVersion = "1.0.0"
      }
    }
  }

We can also add ``TargetFormat.Exe``.

At the commandline, run ``./gradlew packageMsi``. It generates
``project_root/build/compose/binaries/main/msi``.

