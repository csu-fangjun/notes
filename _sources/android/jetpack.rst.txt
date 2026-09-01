jetpack
=======

See also `<https://github.com/android/codelab-android-compose>`_

material design
---------------

.. code-block::

  MaterialTheme(
    colorScheme = MyAppsColorScheme,
    typography = MyAppsTypography,
    shapes = MyAppsShapes,
  ) {
  }

state
-----

.. code-block::

   // var selectedAnswer: MutableState<Answer?> = mutableStateOf(null)
   var selectedAnswer: MutableState<Answer?> = remember { mutableStateOf(null) }
   var selectedAnswer: MutableState<Answer?> = rememberSaveable { mutableStateOf(null) }

   // note that we use the member ``value`` here
   isSelected = (selectedAnswer.value == anwser)

.. code-block::

   var selectedAnswer: Answer? by rememberSaveable { mutableStateOf(null) }

   isSelected = (selectedAnswer == anwser)

.. code-block::

  val mutableState = remember { mutableStateOf(default) }

  var value by remember { mutableStateOf(default) }

  val (value, setValue) = remember { mutableStateOf(default) }

bom
---

`<https://developer.android.com/jetpack/compose/bom/bom-mapping>`_

Arrangement
-----------

`<https://vitor-ramos.medium.com/understand-arrangement-and-alignment-in-jetpack-compose-7633f2ed5b39>`_

- ``Arrangement.Start``, ``Arrangement.Top``
- ``Arrangement.End``, ``Arrangement.Bottom``
- ``Arrangement.Center``
- ``Arrangement.SpaceBetween``
- ``Arrangement.SpaceAround``
- ``Arrangement.SpaceEvenly``
- ``Arrangement.spacedBy(8.dp)``

Alignment
---------

- ``Alignment.Start``
- ``Alignment.End``
- ``Alignment.Center``

Surface
-------

.. code-block::

   Surface(
     modifier =  Modifier.fillMaxSize(),
     color = MaterialTheme.colorscheme.background
   )

   Surface(
     color = MaterialTheme.colorscheme.primary
   )

   Surface(
     color = MaterialTheme.colorscheme.surface,
     shape = RoundedCornerShape(8.dp),
     border = BorderStroke(2.dp, MaterialTheme.colorscheme.surfaceVariant),
     shadowElevation = 8.dp,
     tonalElevation = 8.dp,
   )


Preview
-------

.. code-block::

   @Preview(showBackground=true, showSystemUi=true, name="My name")

   // dark mode
   @Preview(
       showBackground = true,
       widthDp = 320,
       uiMode = UI_MODE_NIGHT_YES,
       name = "GreetingPreviewDark"
   )

Column
------

.. code-block::

   Column(
     verticalArrangement = Arrangement.Center,
     horizontalAlignment = Alignment.CenterHorizontally,
     modifier = modifier.padding(8.dp)
   )

LazyColumn
----------

.. code-block::

  import androidx.compose.foundation.lazy.LazyColumn
  import androidx.compose.foundation.lazy.items


  @Composable
  private fun Greetings(
      modifier: Modifier = Modifier,
      names: List<String> = List(1000) { "$it" }
  ) {
      LazyColumn(modifier = modifier.padding(vertical = 4.dp)) {
          items(items = names) { name ->
              Greeting(name = name)
          }
      }
  }

Row
---

See `<https://developer.android.com/reference/kotlin/androidx/compose/foundation/layout/package-summary#Row(androidx.compose.ui.Modifier,androidx.compose.foundation.layout.Arrangement.Horizontal,androidx.compose.ui.Alignment.Vertical,kotlin.Function1)>`_

.. code-block::

   Row(modifier = Modifier.padding(all = 8.dp))

   Row(
       modifier = Modifier.fillMaxSize(),
       horizontalArrangement = Arrangement.Center,
       verticalAlignment = Alignment.Top
   ) {
   }

   Row(modifier = Modifier.padding(all = 8.dp)) {
     Column(modifier = Modifier.weight(1f)) {
       Text(text = "Hello")
       Text(text = "World")
     }

     ElevatedButton(
       onClick = {}
     ) {
       Text("Show more")
     }
   }

   Row(
       modifier = Modifier
          .fillMaxSize()
          .border(width = 2.dp, color = Color.Green)
   ) {

LazyRow
-------

.. code-block::

  LazyRow(
    horizontalArrangement = Arrangement.spacedBy(8.dp)
  )

  @Composable
  fun AlignYourBodyRow(
     modifier: Modifier = Modifier
  ) {
     LazyRow(
         horizontalArrangement = Arrangement.spacedBy(8.dp),
         contentPadding = PaddingValues(horizontal = 16.dp),
         modifier = modifier
     ) {
         items(alignYourBodyData) { item ->
             AlignYourBodyElement(item.drawable, item.text)
         }
     }
  }


Spacer
------

.. code-block::

   // within a row
   Spacer(modifier = Modifier.width(8.dp))

   // within a column
   Spacer(modifier = Modifier.height(4.dp))

   Spacer(Modifier.height(16.dp))

   Spacker(
     modifier = Modifier
                .matchParentSize()
                .background(color = Color.Gray.copy(alpha = .7f))
   )

Text
----

.. code-block::

   Text(
     text = "Happy Birthday Sam!",
     fontSize = 100.sp,
     lineHeight = 116.sp
     textAlign = TextAlign.Center
   )

   Text(
     text = "From Emma",
     modifier = Modifier.padding(16.dp).align(alignment = Alignment.End)
   )

   Text(text = name, style = MaterialTheme.typography.headlineMedium)

   Text(
      text = name,
      style = MaterialTheme.typography.headlineMedium.copy(
           fontWeight = FontWeight.ExtraBold
      )
   )

   Text(text = stringResource(R.string.ab1_inversions))

   Text(
     "Hello compose",
     Modifier.background(Color.Magenta)
       .size(200.dp, 30.dp)
       .padding(5.dp)
       .alpha(0.5f)
       .align(Alignment.BottomEnd)
       .clickable {}
   )


Button
------

.. code-block::

   Button(
     onclick = {}
   ) {
     Text("Show less")
   }

IconButton
----------

.. code-block::

   IconButton(onClick = {...}) {
     Icon(Icons.Filled.Close, contentDescription = "Close")
   }

Checkbox
--------

.. code-block::

   Checkbox(
     checked = true,
     onCheckedChange = {it->}
   )

Modifier
--------

See `<https://developer.android.com/jetpack/compose/modifiers>`_

.. code-block::

  modifier = Modifier.fillMaxSize()

  modifier = modifier.padding(8.dp)

  modifier = modifier.padding(vertical = 4.dp, horizontal = 8.dp)

  modifier = Modifier.padding(start = 4.dp, end = 8.dp)

  modifier = modifier.padding(bottom = 4.dp)

  modifier = modifier.size(40.dp)

  modifier = modifier.weight(1f)

  modifier = modifier.heightIn(min = 56.dp)

  modifier = Modifier.align(Arrangement.CenterVertically)

  modifier.clip(CircleShape)

  modifier.clickable {
   // some code
  }

  // For a function, it'd better to set the last argument as modifier
  @Composable
  fun MyApp(modifier: Modifier = Modifier) {}


Box
---

.. code-block::

   Box(
     modifier = Modifier.fillMaxSize(),
     contentAlignment = Alignment.Center,
   )

    Box(
        modifier = Modifier
            .padding(all = 2.dp)
            .size(56.dp)
            .background(color = Color.Magenta)
    ) {
    }

Scaffold
--------

.. code-block::

   Scaffold(
     topBar = {
       InfoHeader(...)
     },
     bottomBar = {
       Button(
         onClick = {...}
       ) {
         Text(...)
       }
     }
   ) {
     //
   }

TextField
---------

See `<https://developer.android.com/reference/kotlin/androidx/compose/material3/package-summary#TextField(androidx.compose.ui.text.input.TextFieldValue,kotlin.Function1,androidx.compose.ui.Modifier,kotlin.Boolean,kotlin.Boolean,androidx.compose.ui.text.TextStyle,kotlin.Function0,kotlin.Function0,kotlin.Function0,kotlin.Function0,kotlin.Function0,kotlin.Function0,kotlin.Function0,kotlin.Boolean,androidx.compose.ui.text.input.VisualTransformation,androidx.compose.foundation.text.KeyboardOptions,androidx.compose.foundation.text.KeyboardActions,kotlin.Boolean,kotlin.Int,kotlin.Int,androidx.compose.foundation.interaction.MutableInteractionSource,androidx.compose.ui.graphics.Shape,androidx.compose.material3.TextFieldColors)>`_

.. code-block::

  var text by rememberSaveable(stateSaver = TextFieldValue.Saver) {
      mutableStateOf(TextFieldValue("example", TextRange(0, 7)))
  }

  TextField(
      value = text,
      onValueChange = { text = it },
      label = { Text("Label") }
  )

  TextField(
     value = "",
     onValueChange = {},
     modifier = modifier
         .fillMaxWidth()
         .heightIn(min = 56.dp)
  )

remember
--------

.. code-block::

   // Note we use val here with "= remember"
   val expanded = remember { mutableStateOf(false) }

   expanded.value = !expanded.value

   val extraPadding = if(expanded.value)  48.dp else 0.dp

.. code-block::

   // Note we use var here with "by remember"
   var expanded by remember { mutableStateOf(false) }

   expanded = !expanded

   val extraPadding = if(expanded) 48.dp else 0.dp

.. code-block::

   var expanded by rememberSaveable { mutableStateOf(false) }
   val extraPadding by animateDpAsState {
     if (expanded) 48.dp else 0.dp
   }



Example 1
---------

See `<https://developer.android.com/codelabs/jetpack-compose-basics?continue=https%3A%2F%2Fdeveloper.android.com%2Fcourses%2Fpathways%2Fjetpack-compose-for-android-developers-1%23codelab-https%3A%2F%2Fdeveloper.android.com%2Fcodelabs%2Fjetpack-compose-basics#4>`_

Note how ``Surface`` is used.

.. code-block::

  class MainActivity : ComponentActivity() {
      override fun onCreate(savedInstanceState: Bundle?) {
          super.onCreate(savedInstanceState)
          setContent {
              BasicsCodelabTheme {
                  MyApp(modifier = Modifier.fillMaxSize())
              }
          }
      }
  }

  @Composable
  fun MyApp(modifier: Modifier = Modifier) {
      Surface(
          modifier = modifier,
          color = MaterialTheme.colorScheme.background
      ) {
          Greeting("Android")
      }
  }

  @Composable
  fun Greeting(name: String, modifier: Modifier = Modifier) {
      Surface(color = MaterialTheme.colorScheme.primary) {
          Text(
              text = "Hello $name!",
              modifier = modifier.padding(24.dp)
          )
      }
  }

  @Preview(showBackground = true)
  @Composable
  fun GreetingPreview() {
      BasicsCodelabTheme {
          MyApp()
      }
  }

Example 2
---------

See `<https://developer.android.com/codelabs/jetpack-compose-basics?continue=https%3A%2F%2Fdeveloper.android.com%2Fcourses%2Fpathways%2Fjetpack-compose-for-android-developers-1%23codelab-https%3A%2F%2Fdeveloper.android.com%2Fcodelabs%2Fjetpack-compose-basics#7>`_

Note that we pass a lambda function ``onContinueClicked`` to change the state.

.. code-block::

  @Composable
  fun MyApp(modifier: Modifier = Modifier) {

      var shouldShowOnboarding by remember { mutableStateOf(true) }

      Surface(modifier) {
          if (shouldShowOnboarding) {
              OnboardingScreen(onContinueClicked = { shouldShowOnboarding = false })
          } else {
              Greetings()
          }
      }
  }

  @Composable
  fun OnboardingScreen(
      onContinueClicked: () -> Unit,
      modifier: Modifier = Modifier
  ) {


      Column(
          modifier = modifier.fillMaxSize(),
          verticalArrangement = Arrangement.Center,
          horizontalAlignment = Alignment.CenterHorizontally
      ) {
          Text("Welcome to the Basics Codelab!")
          Button(
              modifier = Modifier
                  .padding(vertical = 24.dp),
              onClick = onContinueClicked
          ) {
              Text("Continue")
          }
      }

  }

  @Preview(showBackground = true, widthDp = 320, heightDp = 320)
  @Composable
  fun OnboardingPreview() {
      BasicsCodelabTheme {
          OnboardingScreen(onContinueClicked = {}) // Do nothing on click.
      }
  }

Example 3
---------

See `<https://developer.android.com/codelabs/jetpack-compose-basics?continue=https%3A%2F%2Fdeveloper.android.com%2Fcourses%2Fpathways%2Fjetpack-compose-for-android-developers-1%23codelab-https%3A%2F%2Fdeveloper.android.com%2Fcodelabs%2Fjetpack-compose-basics#11>`_

Change the colors.

.. code-block::

  // Color.kt

  val Navy = Color(0xFF073042)
  val Blue = Color(0xFF4285F4)
  val LightBlue = Color(0xFFD7EFFE)
  val Chartreuse = Color(0xFFEFF7CF)

.. code-block::

  // Theme.kt

  private val LightColorScheme = lightColorScheme(
      surface = Blue,
      onSurface = Color.White,
      primary = LightBlue,
      onPrimary = Navy
  )

  private val DarkColorScheme = darkColorScheme(
      surface = Blue,
      onSurface = Navy,
      primary = Navy,
      onPrimary = Chartreuse
  )

Example 4
---------

.. code-block::

  @Composable
  fun FavoriteCollectionCard(
     @DrawableRes drawable: Int,
     @StringRes text: Int,
     modifier: Modifier = Modifier
  ) {
     Surface(
         shape = MaterialTheme.shapes.medium,
         color = MaterialTheme.colorScheme.surfaceVariant,
         modifier = modifier
     ) {
         Row(
             verticalAlignment = Alignment.CenterVertically,
             modifier = Modifier.width(255.dp)
         ) {
             Image(
                 painter = painterResource(drawable),
                 contentDescription = null,
                 contentScale = ContentScale.Crop,
                 modifier = Modifier.size(80.dp)
             )
             Text(
                 text = stringResource(text),
                 style = MaterialTheme.typography.titleMedium,
                 modifier = Modifier.padding(horizontal = 16.dp)
             )
         }
     }
  }

  @Preview(showBackground = true, backgroundColor = 0xFFF5F0EE)
  @Composable
  fun FavoriteCollectionCardPreview() {
     MySootheTheme {
         FavoriteCollectionCard(
             text = R.string.fc2_nature_meditations,
             drawable = R.drawable.fc2_nature_meditations,
             modifier = Modifier.padding(8.dp)
         )
     }
  }

Example 5
---------

scroll

.. code-block::

  @Composable
  fun HomeScreen(modifier: Modifier = Modifier) {
     Column(
         modifier
             .verticalScroll(rememberScrollState())
     ) {
         Spacer(Modifier.height(16.dp))
         SearchBar(Modifier.padding(horizontal = 16.dp))
         HomeSection(title = R.string.align_your_body) {
             AlignYourBodyRow()
         }
         HomeSection(title = R.string.favorite_collections) {
             FavoriteCollectionsGrid()
         }
         Spacer(Modifier.height(16.dp))
     }
  }

Example 6
---------

.. code-block::

  @Composable
  fun SingleChoiceQuestion(answers: List<Answer>) {
    Column {
      if(answers.isEmpty()) {
        Text("...")
      } else {
        answers.forEach {answer ->
          Text("...")
        }
      }
    }
  }

Example 7
---------

.. code-block::

  @Composable
  fun MyAppTopAppBar(topAppBarText: String, onBackPressed: () -> Unit) {
      TopAppBar(
          title = {
              Text(
                  text = topAppBarText,
                  textAlign = TextAlign.Center,
                  modifier = Modifier
                      .fillMaxSize()
                      .wrapContentSize(Alignment.Center)
              )
          },
          navigationIcon = {
              IconButton(onClick = onBackPressed) {
                  Icon(
                      Icons.Filled.ArrowBack,
                      contentDescription = localizedString
                  )
              }
          },
          // ...
      )
  }
