Basics-0
========

- Build an iOS app with SwiftUI

  `<https://www.swift.org/getting-started/swiftui/>`_

After creating the project ``WhyNotTry`` and saved in ``~/t``, it creates a
directory ``WhyNotTry`` inside ``~/t``.

Inside ``~/t/WhyNotTry``, there are two directories:

  - ``WhyNotTry``

    Inside ``WhyNotTry``, there are several ``.swift`` files:

      - ``ContentView.swift``
      - ``WhyNotTryApp.swift``

  - ``WhyNotTry.xcodeproj``

    Inside ``WhyNotTry.xcodeproj``, there is a file ``project.xproj``

Content of ``WhyNotTryApp.swift``::

  //
  //  WhyNotTryApp.swift
  //  WhyNotTry
  //
  //  Created by fangjun on 2024/7/25.
  //

  import SwiftUI

  @main
  struct WhyNotTryApp: App {
      var body: some Scene {
          WindowGroup {
              ContentView()
          }
      }
  }



Content of ``ContentView.swift``::

  //
  //  ContentView.swift
  //  WhyNotTry
  //
  //  Created by fangjun on 2024/7/25.
  //

  import SwiftUI

  struct ContentView: View {
      var body: some View {
          VStack {
              Image(systemName: "globe")
                  .imageScale(.large)
                  .foregroundColor(.accentColor)
              Text("Hello, world!")
          }
          .padding()
      }
  }

  struct ContentView_Previews: PreviewProvider {
      static var previews: some View {
          ContentView()
      }
  }


To draw a circle::

  Circle()
    .fill(Color.blue)
    .padding(.all)

Use ``overlay`` to place one view over another, e.g.::

  Circle()
    .fill(Color.blue)
    .padding(.all)
    .overlay(
      Image(systemName: "figure.archery")
        .font(.system(size: 144))
        .foregroundColor(.white)
    )

To add ``Text``::

  Text("Archery")
    .font(.title)

  Text("Archery")
    .font(.largeTitle.bold())

To arrange view vertically, use::

  VStack {
    Circle()
    Text("hello")
  }

My first example ``ContentView.swift``::

  //
  //  ContentView.swift
  //  WhyNotTry
  //
  //  Created by fangjun on 2024/7/25.
  //

  import SwiftUI

  struct ContentView: View {
      let activities = ["Archery", "Baseball", "Basketball"]
      let colors: [Color] = [.blue, .cyan, .gray, .green, .indigo, .mint, .orange, .pink, .purple, .red]
      @State private var selected = "Archery"
      @State private var id = 1
      var body: some View {
          VStack {
              Text("Why not try...")
                  .font(.largeTitle.bold())
              Spacer()
              VStack {
                  Circle()
                      .fill(colors.randomElement() ?? .blue)
                      .padding(/*@START_MENU_TOKEN@*/.all/*@END_MENU_TOKEN@*/)
                      .overlay(
                          Image(systemName: "figure.\(selected.lowercased())")
                              .font(.system(size: 144))
                              .foregroundColor(Color.white)
                      )

                  Text("Archery")
                      .font(.title)
              }
              .transition(.slide)
              .id(id)

              Spacer()

              Button("Try again") {
                  withAnimation(.easeInOut(duration: 1)) {
                      selected = activities.randomElement() ?? "Archery"
                      id += 1
                  }
              }
              .buttonStyle(.borderedProminent)
          }
      }
  }

  struct ContentView_Previews: PreviewProvider {
      static var previews: some View {
          ContentView()
      }
  }

