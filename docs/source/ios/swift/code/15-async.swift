import Foundation // for sleep

func fetchUserID(from server: String) async -> Int {
    let tid =  pthread_self()
    print("fetch userID from \(server) with thread ID \(tid)")
    if server == "primary" {
        return 97
    }

    return 501
}

func fetchUserName(from server: String) async -> String {
    print("fetch userName from \(server) with thread ID \(pthread_self())")
    let userID = await fetchUserID(from: server)
    print("after await fetch userName from \(server) with thread ID \(pthread_self()), user id \(userID)")
    if userID == 501 {
        return "John Appleseed"
    }

    return "Guest"
}

func connectUser(to server: String) async {
    print("here0")
    async let userID = fetchUserID(from: server)
    print("here1")
    async let userName = fetchUserName(from: server)
    print("here2")
    let greeting = await "Hello \(userName), user ID \(userID)"
    print(greeting)
}

if false {
    Task {
        await connectUser(to: "primary")
    }

    sleep(1)
}

if true {
    let userIDs = await withTaskGroup(of: Int.self) { group in
        for server in ["primary", "secondary", "development"] {
            group.addTask {
                return await fetchUserID(from: server)
            }
        }

        var results: [Int] = []

        // for await returns result in completion order, not in adding order
        for await result in group {
            results.append(result)
        }

        return results
    }

    print(userIDs)
}

if true {
    let userNames = await withTaskGroup(of: String.self) { group in
        for server in ["primary", "secondary", "development"] {
            group.addTask {
                return await fetchUserName(from: server)
            }
        }

        var results: [String] = []
        for await result in group {
            results.append(result)
        }

        return results
    }

    print(userNames)
}
